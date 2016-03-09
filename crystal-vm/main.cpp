#include <iostream>
#include "crystalvm.h"

using namespace std;

int main(int argc, char** argv)
{
    string arg(argv[1]);
    VM vm;
    vm.parse(arg);
    vm.run(0);
    return 0;
}
