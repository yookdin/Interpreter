

#include "SymbolGenerator.hpp"

//==========================================================================================================
//==========================================================================================================
SymbolGenerator::SymbolGenerator(string grammar_file, string header_file, string source_file) {
	string_symbol_map["+"] = "ADD";
	string_symbol_map["-"] = "SUB";
	string_symbol_map["*"] = "MUL";
	string_symbol_map["/"] = "DIV";
	string_symbol_map["%"] = "MOD";
	string_symbol_map["="] = "ASSIGN";
	string_symbol_map["=="] = "EQ";
	string_symbol_map["!="] = "NE";
	string_symbol_map["<"] = "LT";
	string_symbol_map[">"] = "GT";
	string_symbol_map["<="] = "LE";
	string_symbol_map[">="] = "GE";
	string_symbol_map["("] = "LEFT_PAREN";
	string_symbol_map[")"] = "RIGHT_PAREN";
	string_symbol_map["{"] = "LEFT_CURLY";
	string_symbol_map["}"] = "RIGHT_CURLY";
	string_symbol_map["~"] = "STRING_MATCH";
	string_symbol_map["!~"] = "NO_STRING_MATCH";
	string_symbol_map[";"] = "SEMI_COLON";
	string_symbol_map["?"] = "QUESTION_MARK";
    string_symbol_map[":"] = "COLON";
    string_symbol_map["$"] = "EOI";
    

	read_file(grammar_file);
	write_header_file(header_file);
    write_source_file(source_file, header_file);
}

//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::read_file(string filename) {
	ifstream file = ifstream(filename);

	if(!file.is_open())
		throw string("File " + filename + " not found");

	for(string line; getline(file, line);) {
		trim(line); // Must trim! o/w stringstream gets confused!
		line = line.substr(0, line.find_first_of('#'));
		regex production_re("(\\w+)\\s*->\\s*(.*)"); // Note: the RHS needs to parsed word by word
		smatch match_res;

		if(not regex_match(line, match_res, production_re))
			throw string("Unknown production in line:\n" + line);

		nonterminals.insert(match_res[1]);

		stringstream sts(match_res[2]);
		string symbol_str;

		while(!sts.eof()) { // Extract the symbol names
			sts >> symbol_str;
			if(string_symbol_map.count(symbol_str) == 0)
				terminals.insert(symbol_str); // This will insert also nonterminals, that will later be removed
		} 
	}

	for(auto& n: nonterminals)
		if(terminals.count(n) != 0)
			terminals.erase(n);
	file.close();
}


//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_header_file(string filename) {
	ofstream file = ofstream(filename);

	if(!file.is_open())
		throw string("File " + filename + " can't be written");

    string tab = "    ";
    
    file << "// Generated Symbol header file" << endl << endl;
    file << "#include \"bimap.h\"" << endl << endl;
 
    
    //------------------------------------------------------------------------------------------------------
    // Write enum
    //------------------------------------------------------------------------------------------------------
    file << "//==========================================================================================================" << endl;
    file << "// The symbols of the language (terminals and nonterminals" << endl;
    file << "//==========================================================================================================" << endl;
    file << "enum Symbol {" << endl;
	file << "	START = -1," << endl << tab;

	for(auto& n: nonterminals)
		file << n << ", ";
	file << endl << tab;

	int n = 0;
	for(auto& p: string_symbol_map) {
		file << p.second << ", ";
		if(++n % 10 == 0)
			file << endl << tab;
	}
	
	for(auto& t: terminals) {
		string upcase = t;
		transform(upcase.begin(), upcase.end(), upcase.begin(), ::toupper);
 		file << upcase << ", ";

		if(++n % 10 == 0)
			file << endl << tab;
	}

	file << endl;
	file << "};" << endl << endl;

    // Macros
    file << "#define NUM_SYMBOLS " << nonterminals.size() + string_symbol_map.size() + terminals.size() << endl;
	file << "#define NUM_NON_TERMINALS " << nonterminals.size() << endl << endl;

    // Utility functions
	file << "bool is_nonterminal(Symbol s);" << endl;
    file << "bool is_terminal(Symbol s);" << endl << endl;

    // Symbol string map declaration
    file << "// A bidirectional map of Symbols and their string representation" << endl;
    file << "extern bimap<Symbol, string> symbol_str_map;" << endl;
    
    
	file.close();
}


//==========================================================================================================
//==========================================================================================================
void SymbolGenerator::write_source_file(string src_filename, string header_filename) {
    ofstream file = ofstream(src_filename);
    
    if(!file.is_open())
        throw string("File " + src_filename + " can't be written");
    
    header_filename = basename(header_filename);
    
    file << "// Generated Symbol source file" << endl << endl;
    file << "#include \"" << header_filename << "\"" << endl << endl;
    file << "bool is_nonterminal(Symbol s) { return s < NUM_NON_TERMINALS; }" << endl;
    file << "bool is_terminal(Symbol s) { return not is_nonterminal(s); }" << endl << endl;

    string tab = "    ";
    
    //------------------------------------------------------------------------------------------------------
    // Symbol string map definition
    //------------------------------------------------------------------------------------------------------
    file << "bimap<Symbol, string> symbol_str_map = {" << endl << tab; 
    
    int n = 0;
    for(auto& nt: nonterminals) {
        file << "{" << nt << ", \"" << nt << "\"}, ";
        if(++n % 10 == 0)
            file << endl << tab;
    }
    
    file << endl << tab;
    n = 0;
    for(auto& p: string_symbol_map) {
        file << "{" << p.second << ", \"" << p.first << "\"}, ";
        if(++n % 10 == 0)
            file << endl << tab;
    }
    
    for(auto& t: terminals) {
        string upcase = t;
        transform(upcase.begin(), upcase.end(), upcase.begin(), ::toupper);
        file << "{" << upcase << ", \"" << t << "\"}, ";
        if(++n % 10 == 0)
            file << endl << tab;
    }

    file << endl << "};" << endl;
    file.close();
}
    
    
//==========================================================================================================
// Remove leading and trailing spaces and comment (//...)
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
    {
        line.erase(pos);
    }
    
    line.erase(line.find_last_not_of(spaces) + 1);
    return line;
}


//======================================================================================================================
// Return the file name part of a path
//======================================================================================================================
string SymbolGenerator::basename(string path)
{
    // This works even if no / in path, becaue string::npos + 1 = 0
    return path.substr(path.find_last_of('/') + 1);
}






