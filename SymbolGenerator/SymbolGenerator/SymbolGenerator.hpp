#ifndef _SYMBOL_GENERATOR_HPP_
#define  _SYMBOL_GENERATOR_HPP_

#include <map>
#include <string>
#include <set>
#include <fstream>
#include <regex>
#include <sstream>

using namespace std;

class SymbolGenerator {
public:
	SymbolGenerator(string grammar_file, string header_file, string source_file);

private:
	map<string, string> string_symbol_map;
	set<string> terminals;
	set<string> nonterminals;

	void read_file(string filename);
	void write_header_file(string filename);
    void write_source_file(string src_filename, string header_filename);
    
    string basename(string path);
    string& trim(string& line);
};

#endif // _SYMBOL_GENERATOR_HPP_