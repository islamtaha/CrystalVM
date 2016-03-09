#include<iostream>
#include "lexer.h"

using namespace std;

string lexer::read_file(string file_name){
    infile.open(file_name);
    string content;
    content.assign( istreambuf_iterator<char>(infile), istreambuf_iterator<char>() );
    return content;

}


int lexer::get_opcode_num(string n){
    int num = -1;
    if(strcmp(n.c_str(), "ADD") == 0){
        num = 0;
    }else if(strcmp(n.c_str(), "SUB") == 0){
        num = 1;
    }else if(strcmp(n.c_str(), "MUL") == 0){
        num = 2;
    }else if(strcmp(n.c_str(), "DEC") == 0){
        num = 3;
    }else if(strcmp(n.c_str(), "INC") == 0){
        num = 4;
    }else if(strcmp(n.c_str(), "ILT") == 0){
        num = 5;
    }else if(strcmp(n.c_str(), "IEQ") == 0){
        num = 6;
    }else if(strcmp(n.c_str(), "JMP") == 0){
        num = 7;
    }else if(strcmp(n.c_str(), "JMPT") == 0){
        num = 8;
    }else if(strcmp(n.c_str(), "JMPF") == 0){
        num = 9;
    }else if(strcmp(n.c_str(), "PUSH") == 0){
        num = 10;
    }else if(strcmp(n.c_str(), "AND") == 0){
        num = 11;
    }else if(strcmp(n.c_str(), "OR") == 0){
        num = 12;
    }else if(strcmp(n.c_str(), "XOR") == 0){
        num = 13;
    }else if(strcmp(n.c_str(), "NOT") == 0){
        num = 14;
    }else if(strcmp(n.c_str(), "LOAD") == 0){
        num = 15;
    }else if(strcmp(n.c_str(), "GLOAD") == 0){
        num = 16;
    }else if(strcmp(n.c_str(), "STORE") == 0){
        num = 17;
    }else if(strcmp(n.c_str(), "GSTORE") == 0){
        num = 18;
    }else if(strcmp(n.c_str(), "PRINT") == 0){
        num = 19;
    }else if(strcmp(n.c_str(), "POP") == 0){
        num = 20;
    }else if(strcmp(n.c_str(), "CALL") == 0){
        num = 21;
    }else if(strcmp(n.c_str(), "RET") == 0){
        num = 22;
    }else if(strcmp(n.c_str(), "NOP") == 0){
        num = 23;
    }else if(strcmp(n.c_str(), "DROP") == 0){
        num = 24;
    }else if(strcmp(n.c_str(), "SWAP") == 0){
        num = 25;
    }else if(strcmp(n.c_str(), "EXIT") == 0){
        num = 26;
    }else{
        printf("invalid opcode: %s", n.c_str());
        exit(1);
    }
    return num;
}

lexer::~lexer(){
    infile.close();
}


vector<string> lexer::get_tokens(string prog){
    vector<string> arr;
    string token = "";
    for(int i = 0; i < prog.size(); i++){
        if(prog[i] == ' ' || prog[i] == '\n'){
            if(strcmp(token.c_str(), "") == 0){
                continue;
            }
            arr.push_back(token);
            token = "";
        }else{
            token = token +  prog[i];
        }
    }
    return arr;
}

inline bool is_int(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

   char * p ;
   strtol(s.c_str(), &p, 10) ;

   return (*p == 0) ;
}



vector<int> lexer::get_program_to_int(vector<string> args){
    vector<int> arr;
    for(int i =0 ;i < args.size(); i++){
        if(is_int(args[i])){
            int num = atoi(args[i].c_str());
            arr.push_back(num);
        }else{
            arr.push_back(get_opcode_num(args[i]));
        }
    }
    return arr;
}



vector<int> lexer::get_prog(string arg){
    string prog = read_file(arg);
    vector<string> tokens = get_tokens(prog);
    vector<int> ret = get_program_to_int(tokens);
    return ret;
}
