#ifndef _SYMBOL_GENERATOR_HPP_
#define  _SYMBOL_GENERATOR_HPP_

#include <iostream>
#include <map>
#include <unordered_set>
#include <string>
#include <set>
#include <fstream>
#include <regex>
#include <sstream>

using namespace std;

class SymbolGenerator {
public:
    SymbolGenerator(string grammar_file, string output_dir);

private:
    ofstream operators_hdr_file;
	map<string, string> keyword_symbol_map;
	set<string> terminals;
	set<string> nonterminals;

    // To uniquely define the operator we need the name and also the number of parameters
    map<pair<string, int>, string> operators_class_names;
    unordered_set<string> operators;
    
    void read_file(string filename);
    bool parse_keyword_line(string &line);
    bool parse_operator_line(string &line);
    bool parse_production_line(string &line);

    void write_symbols_hdr_file(string filename);
    void write_symbols_src_file(string src_filename);
    void write_operators_hdr_file_start();
    void write_operators_hdr_file_end();
    void write_operators_src_file(string src_filename, string hdr_filename);
    void write_kewords_regex_file(string filename);
    
    string symbol_to_class_name(string &name);
    string basename(string path);
    string& trim(string& line);
    void write_pair(ofstream& file, string symbol_enum, string symbol_name = "");
};

#endif // _SYMBOL_GENERATOR_HPP_
