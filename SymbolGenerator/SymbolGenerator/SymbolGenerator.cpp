

#include "SymbolGenerator.hpp"


//==========================================================================================================
//==========================================================================================================
SymbolGenerator::SymbolGenerator(string grammar_file, string output_dir) {
    string operators_hdr_filename = output_dir + "/OperatorClasses.hpp";
    string operators_src_filename = output_dir + "/OperatorClasses.cpp";
    string symbols_hdr_filename = output_dir + "/Symbol.hpp";
    string symbols_src_filename = output_dir + "/Symbol.cpp";
    string keywords_regex_file = output_dir + "/LexerKeywords.cpp"; // The regex is used by the Lexer class
    
    operators_hdr_file.open(operators_hdr_filename);
    
    if(not operators_hdr_file.is_open())
        throw string("Couldn't open " + operators_hdr_filename);
    
    write_operators_hdr_file_start();
    read_file(grammar_file);
    terminals.insert("EOI"); // Add special terminal for indicating End-Of-Input
    write_operators_hdr_file_end();
    write_symbols_hdr_file(symbols_hdr_filename);
    write_symbols_src_file(symbols_src_filename);
    write_operators_src_file(operators_src_filename, basename(operators_hdr_filename));
    write_kewords_regex_file(keywords_regex_file);
}


//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_operators_hdr_file_start() {
    operators_hdr_file <<
R"(
// Generated file, do not change manually!

#ifndef operator_classes_hpp
#define operator_classes_hpp
    
#include "Operator.hpp"
#include "bimap.h"
    
)";
}


//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_operators_hdr_file_end() {
    operators_hdr_file << endl << "#endif // operator_classes_hpp" << endl;
}


//==========================================================================================================
// There are three kind of lines in a grammar file:
// Keyword mapping:
// keyword: <keyword> <symbol>
// Operator definition:
// operator: <keyword> <operands> <precedence> <associativity> <class> <function> <exectuable> 
// Production:
// N -> S1 S2 ...
//==========================================================================================================
void SymbolGenerator::read_file(string filename) {
    ifstream file(filename);
    
    if(not file)
        throw string("File " + filename + " not found");    
    
    for(string line; getline(file, line);) {
        trim(line); // Must trim! o/w stringstream gets confused!
        
        if(line.empty())
            continue;
        
        // Try parsing the different kinds of lines
        if(not parse_keyword_line(line) and not parse_operator_line(line) and not parse_production_line(line)) {
            throw string("Unknown syntax:\n" + line);
        }
    }
    
    for(auto& n: nonterminals)
        if(terminals.count(n) != 0)
            terminals.erase(n);
}


//==========================================================================================================
//==========================================================================================================
bool SymbolGenerator::parse_keyword_line(string &line) {
    regex re("keyword: *([^ ]+) *([^ ]+)");
    smatch match;
    
    if(not regex_match(line, match, re))
        return false;
    
    keyword_symbol_map[match[1]] = match[2];
    return true;
}


//==========================================================================================================
// If the line is an operator definition line, write an operator class code into the operators header file
//==========================================================================================================
bool SymbolGenerator::parse_operator_line(string &line) {
    regex start_re("^operator *:");
    smatch match;
    
    if(not regex_search(line, match, start_re))
        return false;
    
    //------------------------------------------------------------------------------------------------------ 
    // Extract the operator line parameters into variables
    //------------------------------------------------------------------------------------------------------ 
    stringstream sts(match.suffix());
    
    vector<string> param_names = {"keyword", "operands", "precedence", "associativity", "class", "function", "executable"};
    map<string, string> params_map;
    
    for(int i = 0; i < param_names.size(); ++i) {
        if(sts.eof()) {
            throw string("Wrnog format of operator line: " + line);
        }
        
        string word;
        sts >> word;
        params_map[param_names[i]] = word;
    }
    
    if(not sts.eof()) {
        throw string("Wrnog format of operator line: " + line);
    }
    
    string keyword = params_map["keyword"], precedence = params_map["precedence"],
        associativity = params_map["associativity"], class_name = params_map["class"], function = params_map["function"];
    string symbol = keyword_symbol_map[keyword];
    
    if(class_name == "*") {
        class_name = symbol_to_class_name(symbol); 
    }
    
    int operands = stoi(params_map["operands"]);
    bool executable = (params_map["executable"] == "YES" or params_map["executable"] == "*");
    
    // This is used for creating the OperatorsClasses.cpp file
    operators_class_names[{symbol, operands}] = class_name;
    operators.insert(symbol);
    
    //------------------------------------------------------------------------------------------------------
    // Write to operators header file a class based on the parameters read
    //------------------------------------------------------------------------------------------------------
    auto &file = operators_hdr_file;
    file << "//==========================================================================================================" << endl;
    file << "//==========================================================================================================" << endl;
    file << "class " << class_name << ": public Operator {" << endl;
    file << "public:" << endl;
    file << "    " << class_name << "(): Operator(" << symbol << ", " << operands << ", " << precedence << ", " << associativity << ") {}" << endl;
    file << "protected:" << endl;
    file << "    SharedValue execute(vector<SharedValue>& operands) const override {" << endl;
    
    if(not executable) {
        file << "        throw string(\"Operator " << symbol << " should never be executed\");" << endl; 
    }
    else if(function == "*") {
        if(operands == 2) {
            file << "        return SharedValue( &(*operands[0] " << keyword << " *operands[1]) );" << endl;
        }
        // Note: currenlty only prefix unary operators exist!
        else if(operands == 1) {
            file << "        return SharedValue(&(" << keyword << "(*operands[0])));" << endl;
        }
        else {
            throw string("Unsupported number of parameters for operator " + symbol + ": " + to_string(operands));
        }
    }
    else {
        if(operands == 2) {
            file << "        return SharedValue(operands[0]->" << function << "(operands[1]));" << endl;
        }
        else {
            throw string("Unsupported number of parameters for operator " + symbol + ": " + to_string(operands));
        }
    }
    
    file << "    }" << endl;
    file << "};" << endl << endl << endl;
    
    return true;
}


//==========================================================================================================
// Note: the symbol generator ignores the action part of the line, which will be read and used by the parser
// generator.
//==========================================================================================================
bool SymbolGenerator::parse_production_line(string &line) {
    line = line.substr(0, line.find_first_of('#'));
    regex production_re("(\\w+)\\s*->\\s*(.*)"); // Note: the RHS needs to be parsed word by word
    smatch match_res;
    
    if(not regex_match(line, match_res, production_re))
        return false;
    
    nonterminals.insert(match_res[1]);
    
    stringstream sts(match_res[2]);
    string symbol_str;
    
    while(not sts.eof()) { // Extract the symbol names
        sts >> symbol_str;
        if(keyword_symbol_map.count(symbol_str) == 0)
            terminals.insert(symbol_str); // This will insert also nonterminals, that will later be removed
    } 
    
    return true;
}


//==========================================================================================================
//==========================================================================================================
string SymbolGenerator::symbol_to_class_name(string &name) {
    string res = name;
    
    for(int i = 0; i < res.size(); ++i) {
        if(i > 0 and isalpha(res[i-1])) {
            res[i] = tolower(res[i]);
        }
    }
    
    return regex_replace(res, regex("_"), "");
}


//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_symbols_hdr_file(string filename) {
    ofstream file = ofstream(filename);
    
    if(not file)
        throw string("File " + filename + " can't be written");
    
    string tab = "    ";
    
    file << "// Generated Symbol header file, do not change manually!" << endl << endl;
    file << "#ifndef symbol_hpp" << endl;
    file << "#define symbol_hpp" << endl << endl;
    file << "#include \"bimap.h\"" << endl << endl;
    
    
    //------------------------------------------------------------------------------------------------------
    // Write enum
    //------------------------------------------------------------------------------------------------------
    file << "//============================================================================================================" << endl;
    file << "// The symbols of the language (terminals and nonterminals)." << endl;
    file << "// The nonterminals appear first." << endl; 
    file << "//============================================================================================================" << endl;
    file << "enum Symbol {" << endl;
    
    
    //------------------------------------------------------------------------------------------------------
    // Write nonterminals
    //------------------------------------------------------------------------------------------------------
    file << tab << "// Nonterminals" << endl;
    file << tab << "START = -1, ";
    
    int line_length = 16, max_line_length = 110;
    
    for(auto& name: nonterminals) {
        if(line_length + name.length() + 1 > max_line_length) {
            file << endl << tab;
            line_length = (int)tab.length();
        }
        
        file << name << ", ";
        line_length += name.length() + 2;
    }
    
    //------------------------------------------------------------------------------------------------------
    // Write terminals
    //------------------------------------------------------------------------------------------------------
    file << endl << endl << tab << "// Terminals" << endl << tab;
    line_length = 4;
    
    for(auto& p: keyword_symbol_map) {
        string name = p.second;
        
        if(line_length + name.length() + 1 > max_line_length) {
            file << endl << tab;
            line_length = (int)tab.length();
        }
        
        file << name << ", ";
        line_length += name.length() + 2;
    }
    
    for(auto& t: terminals) {
        string name = t;
        transform(name.begin(), name.end(), name.begin(), ::toupper);
        
        if(line_length + name.length() + 1 > max_line_length) {
            file << endl << tab;
            line_length = (int)tab.length();
        }
        
        file << name << ", ";
        line_length += name.length() + 2;
    }
    
    file << endl;
    file << "};" << endl << endl;
    
    // Macros
    file << "#define NUM_SYMBOLS " << nonterminals.size() + keyword_symbol_map.size() + terminals.size() << endl;
    file << "#define NUM_NON_TERMINALS " << nonterminals.size() << endl << endl;
    
    // Utility functions
    file << "bool is_nonterminal(Symbol s);" << endl;
    file << "bool is_terminal(Symbol s);" << endl << endl;
    
    // Symbol string map declaration
    file << "// A bidirectional map of Symbols and their string representation" << endl;
    file << "extern bimap<Symbol, string> symbol_str_map;" << endl;
    
    file << endl << "#endif // symbol_hpp" << endl;
}
    

//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_symbols_src_file(string src_filename) {
    ofstream file = ofstream(src_filename);
    
    if(not file)
        throw string("File " + src_filename + " can't be written");
    
    string header_filename = basename(src_filename);
    header_filename = regex_replace(header_filename, regex("\\.cpp"), ".hpp");
    
    file << "// Generated Symbol source file, do not change manually!" << endl << endl;
    file << "#include \"" << header_filename << "\"" << endl << endl;
    file <<
R"(
bool is_nonterminal(Symbol s) {
    return s < NUM_NON_TERMINALS;
}

bool is_terminal(Symbol s) {
    return not is_nonterminal(s);
}

)";
    
    //------------------------------------------------------------------------------------------------------
    // Symbol string map definition
    //------------------------------------------------------------------------------------------------------
    file << "bimap<Symbol, string> symbol_str_map = {" << endl; 
    
    write_pair(file, "START");
    
    for(auto& nt: nonterminals) {
        write_pair(file, nt);
    }
    
    for(auto& p: keyword_symbol_map) {
        write_pair(file, p.second, p.first);
    }
    
    for(auto& t: terminals) {
        string upcase = t;
        transform(upcase.begin(), upcase.end(), upcase.begin(), ::toupper);
        write_pair(file, upcase, t);
    }
    
    file << "};" << endl;
    file.close();
}


//======================================================================================================================
//======================================================================================================================
void SymbolGenerator::write_operators_src_file(string src_filename, string hdr_filename) {
    ofstream file = ofstream(src_filename);
    
    if(not file.is_open())
        throw string("File " + src_filename + " can't be written");
        
    file << "// Generated Operator source file, do not change manually!" << endl << endl;
    file << "#include \"" << hdr_filename << "\"" << endl << endl;

    file << "//==========================================================================================================" << endl;
    file << "// Set of operator symbols" << endl;
    file << "//==========================================================================================================" << endl;
    file << "set<Symbol> operators = {" << endl;
    ostringstream line;
    line << "    ";
    
    for(auto &name: operators) {
        if(line.str().length() >= 100) {
            file << line.str() << endl;
            line.str(""); // Clear the stream
            line << "    ";
        }
        
        line << name + ", "; 
    }
    
    file << line.str();
    
    file << endl << "};" << endl << endl;
    
    file << "//==========================================================================================================" << endl;
    file << "// Map of operators. Keys are pair of the operator symbol and the number of operands, to enable operators " << endl;
    file << "// with the same name (like '-', that is both binary subtract and unary negation)" << endl;
    file << "//==========================================================================================================" << endl;
    file << "map<pair<Symbol, int>, Operator*> sym_op_map = {" << endl;
    
    for(auto &p: operators_class_names) {
        file.width(30);
        file << std::left << "    {{" + p.first.first + ", " + to_string(p.first.second) + "}, "; 
        file << "new " << p.second << "()}," << endl;
    }
    
    file << "};" << endl << endl;
    file <<
R"(
//==========================================================================================================
//==========================================================================================================
bool is_op(Symbol s) {
    return operators.count(s) != 0; 
}

//==========================================================================================================
//==========================================================================================================
Operator* get_op(Symbol s, int num_operands) {
    return sym_op_map[{s, num_operands}];
} 

)";
}


//======================================================================================================================
// Write the lexer kewords regex
//======================================================================================================================
void SymbolGenerator::write_kewords_regex_file(string filename) {
    ofstream file = ofstream(filename);
    
    if(not file.is_open())
        throw string("File " + filename + " can't be written");

    string regex_operators = "+*?()[]{}."; // These characaters need to be escaped to have literal meaning
    
    file << "// Generated file, do not change manually!" << endl << endl;
    file << "#include \"Lexer.hpp\"" << endl << endl;
    file << "const regex Lexer::keyword_re(\"^(";
    
    vector<string> keywords, keysigns;
    regex word_re("\\w+");
    
    for(auto p: keyword_symbol_map) {
        if(regex_match(p.first, word_re))
           keywords.push_back(p.first);
        else
            keysigns.push_back(p.first);
    }
    
    // Sort keywords by decreasing length, so that if two keywords have the same prefix the longer will
    // be matched first (like '<' and '<=')
    std::sort(keywords.begin(), keywords.end(),
              [](const string &s1, const string &s2) {
                  return s1.size() > s2.size();
              });

    std::sort(keysigns.begin(), keysigns.end(),
              [](const string &s1, const string &s2) {
                  return s1.size() > s2.size();
              });
    
    if(not keysigns.empty()) {
        file << "(";
        
        for(int i = 0; i < keysigns.size(); ++i) {
            for(auto c: keysigns[i]) {
                if(regex_operators.find(c) != string::npos )
                    file << "\\\\";
                file << c;
            }
            
            if(i < keysigns.size() - 1)
                file << "|";
        }
        
        file << ")";        
    }
    
    if(not keywords.empty()) {
        file << "|(";
        
        for(int i = 0; i < keywords.size(); ++i) {
            file << keywords[i];
            
            if(i < keywords.size() - 1)
                file << "|";
        }
        
        file << ")\\\\b";
        
    }

    file << ")\");" << endl;
}


//======================================================================================================================
//======================================================================================================================
void SymbolGenerator::write_pair(ofstream& file, string symbol_enum, string symbol_name) {
    string s = symbol_enum + ", ";
    file << "    {";
    file.width(20);
    file << std::left << s;
    
    if(symbol_name.empty())
        symbol_name = symbol_enum;
    
    file << "\"" << symbol_name << "\"}," << endl;
}

    
//======================================================================================================================
// Return the file name part of a path
//======================================================================================================================
string SymbolGenerator::basename(string path)
{
    // This works even if no / in path, becaue string::npos + 1 = 0
    return path.substr(path.find_last_of('/') + 1);
}

//==========================================================================================================
// Remove leading and trailing spaces and comment
//==========================================================================================================
string& SymbolGenerator::trim(string& line) {
    if(line.empty())
    {
        return line;
    }
    
    string spaces = " \t\n\r";
    line.erase(0, line.find_first_not_of(spaces));
    
    size_t pos = line.find("//");
    if(pos != string::npos)
        line.erase(pos);
    
    line.erase(line.find_last_not_of(spaces) + 1);
    return line;
}




