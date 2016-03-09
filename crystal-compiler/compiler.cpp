#include "compiler.h"

int compiler::run(string argv){
    ofstream outfile;
    outfile.open("../../../test/out.crystal");
    lexer lex;
    vector<int> prog = lex.get_prog(argv);
    for(int i = 0; i < prog.size(); i++){
        outfile << prog[i] << " ";
    }
    return 0;
}
