#include "compiler.h"
using namespace std;

int main(int argc, char ** argv){
    compiler compile;
    string arg(argv[1]);
    compile.run(arg);

    return 0;
}
