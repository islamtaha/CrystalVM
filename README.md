CrystalVM
=========
CrystalVM is a simple stack-based virtual machine that works with 27 instructions implemented c++

the project contains:
* [crystal vm](crystal-vm)
  * A simple, stack-based virtual machine for executing the assembly instructions.
* [crystal compiler](crystal-compiler)
  * This will translate from assembly-source into binary-opcodes in the form of .crystal file.


the main aim of this project is to understand how computer works and how instructions are run in the cpu

this virtual machine doesn't compile directly to machine code

it just understands the opcode and then run on c++ and c++ compiler change it to machine code

How to Run
==========

first you must change the assembly into binary opcode so the vm would understand it

To compile using the compiler:

    $ ./crystal-compiler/bin/Debug/crystal-compiler filename
 
this will generate .crystal file in the test folder 

then you need to send the .crystal file to the vm To excute it: 

    $ ./crytal-vm/bin/Debug/crystal-vm out.crystal
  
Instruction set
===============

    opcode  val    	        function
    ---------------------------------------------------------------------
    ADD     0       add the two top elements in the stack 
    SUB     1       add the two top elements in the stack
    MUL     2       add the two top elements in the stack
    DEC     3       decrement the top of the stack
    INC     4       increment the top of the stack
    ILT     5       pop a, then pop b, then if b < a excute the next instruction else skip the next instruction
    IEQ     6       pop a, then pop b, then if b = a excute the next instruction else skip the next instruction
    JMP     7       jump to a curtain inctruction number
    JMPT    8       pop the top of the stack and check if it is true then move to intsruction number
    JMPF    9       pop the top of the stack and check if it is false then move to intsruction number
    PUSH    10      push value to the top of the stack
    AND     11      do and operation on the two top elements in the stack
    OR      12      do or operation on the two top elements in the stack
    XOR     13      do xor operation on the two top elements in the stack
    NOT     14      do not operation on the top element in the stack
    LOAD    15      load a value to the top of the stack from local memeory
    GLOAD   16      load a value to the top of the stack from global memeory
    STORE   17      pop the top of stack and store it in some local address memory
    GSTORE  18      pop the top of stack and store it in some global address memory
    PRINT   19      pop the top of the stack then print it
    POP     20      pop the top of the stack
    CALL    21      function call takes the address of the function and number of arguments of the function and the arguments are took from the top of the stack
    RET     22      return
    NOP     23      do nothing
    DROP    24      drop the value on top od the stack or remove it
    SWAP    25      swap the top two values in the stack
    EXIT    26      exit program
