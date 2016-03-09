#ifndef LEXER_H_
#define LEXER_H_

#include<string.h>
#include<vector>
#include <fstream>

using namespace std;

class lexer{
public:
    string read_file(string file_name);
    vector<int> get_prog(string arg);
    ~lexer();

private:
    ifstream infile;
    int get_opcode_num(string n);
    vector<string> get_tokens(string prog);
    vector<int> get_program_to_int(vector<string> args);
};


#endif
