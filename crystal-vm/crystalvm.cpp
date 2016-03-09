#include "crystalvm.h"
#include "lexer.h"
using namespace std;


void VM::run(int startip){
    ip = startip;
    sp = -1;
    callsp = -1;
    int opcode = opCode[ip];

    while (opcode != EXIT && ip < opCode.size()) {
        ip++;
        switch (opcode) {
            case ADD:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a + b;
                break;
            case SUB:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a - b;
                break;
            case MUL:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a * b;
                break;
            case DEC:
                stack[sp] = stack[sp]-1;
                break;
            case INC:
                stack[sp] = stack[sp]+1;
                break;
            case ILT:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = (a < b) ? true : false;
                break;
            case NOP:
                ip++;
                break;
            case DROP:
                sp--;
                break;
            case SWAP:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = b;
                stack[++sp] = a;
                break;
            case IEQ:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = (a == b) ? true : false;
                break;
            case JMP:
                ip = opCode[ip];
                break;
            case JMPT:
                addr = opCode[ip++];
                if (stack[sp--] == true) ip = addr;
                break;
            case JMPF:
                addr = opCode[ip++];
                if (stack[sp--] == false) ip = addr;
                break;
            case PUSH:
                stack[++sp] = opCode[ip++];
                break;
            case AND:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a & b;
                break;
            case OR:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a | b;
                break;
            case XOR:
                b = stack[sp--];
                a = stack[sp--];
                stack[++sp] = a ^ b;
                break;
            case NOT:
                a = stack[sp--];
                stack[++sp] = !a;
                break;
            case LOAD:
                offset = opCode[ip++];
                stack[++sp] = call_stack[callsp].local_memory[offset];
                break;
            case GLOAD:
                addr = opCode[ip++];
                stack[++sp] = memory[addr];
                break;
            case STORE:
                offset = opCode[ip++];
                call_stack[callsp].local_memory[offset] = stack[sp--];
                break;
            case GSTORE:
                addr = opCode[ip++];
                memory[addr] = stack[sp--];
                break;
            case PRINT:
                printf("%d\n", stack[sp--]);
                break;
            case POP:
                --sp;
                break;
            case CALL:{
                addr = opCode[ip++];
                int nargs = opCode[ip++];
                int nlocals = opCode[ip++];
                ++callsp;
                stack_frame_init(&call_stack[callsp], ip, nargs+nlocals);
                for (int i=0; i<nargs; i++) {
                    call_stack[callsp].local_memory[i] = stack[sp-i];
                }
                sp -= nargs;
                ip = addr;
                break;
                }
            case RET:
                ip = call_stack[callsp].returnip;
                callsp--;
                break;
            default:
                printf("invalid opcode: %d at ip=%d\n", opcode, (ip - 1));
                exit(1);
        }
        opcode = opCode[ip];
    }
}


void VM::stack_frame_init(stack_frame *frame, int ip, int local_memory) {
    if (local_memory > DEFAULT_LOCAL_MEMORY) {
        fprintf(stderr, "too many locals variables requested for local memory", local_memory);
    }
    frame->returnip = ip;
}



void VM::parse(string arg){
    lexer lex;
    vector<int> prog = lex.get_prog(arg);
    opCode = prog;
}

