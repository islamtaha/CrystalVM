#ifndef CRYSTALVM_H_
#define CRYSTALVM_H_

#include <vector>
#include <string>

#define true 1
#define false 0
#define DEFAULT_STACK_SIZE       1000
#define DEFAULT_STACK_FRAME_SIZE 100
#define DEFAULT_LOCAL_MEMORY     100


using namespace std;

typedef enum {
    ADD     = 0,
    SUB     = 1,
    MUL     = 2,
    DEC     = 3,
    INC     = 4,
    ILT     = 5,
    IEQ     = 6,
    JMP     = 7,
    JMPT    = 8,
    JMPF    = 9,
    PUSH    = 10,
    AND     = 11,
    OR      = 12,
    XOR     = 13,
    NOT     = 14,
    LOAD    = 15,
    GLOAD   = 16,
    STORE   = 17,
    GSTORE  = 18,
    PRINT   = 19,
    POP     = 20,
    CALL    = 21,
    RET     = 22,
    NOP     = 23,
    DROP    = 24,
    SWAP    = 25,
    EXIT    = 26
} instructions;



typedef struct {
    int returnip;
    int local_memory[DEFAULT_LOCAL_MEMORY];
} stack_frame;



class VM{
public:
    int ip;
    int sp;
    int callsp;
    int a = 0;
    int b = 0;
    int addr = 0;
    int offset = 0;
    vector<int> opCode;
    vector<int> memory;
    int stack[DEFAULT_STACK_SIZE];
    stack_frame call_stack[DEFAULT_STACK_FRAME_SIZE];
    void run(int startip);
    void parse(string arg);
    void stack_frame_init(stack_frame *call, int ip, int local_memory);
};



#endif
