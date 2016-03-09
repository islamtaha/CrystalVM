CrystalVM
=========
CrystalVM is a simple stack-based virtual machine that works with 27 instructions implemented c++

the project contains:
* [crystal vm](crystal-vm)
  * A simple, stack-based virtual machine for executing the assembly instructions.
* [crystal compiler](crystal-compiler)
  * This will translate from assembly-source into binary-opcodes.

this virtual machine has only a stack it doesn't have registers.
the main aim of this project is to understand how computer works and how instructions are run in the cpu

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
ADD     0x00000000      pop a, then pop b, then push a + b 
SUB     0x00000001      pop a, then pop b, then push a - b
MUL     0x00000002      pop a, then pop b, then push a * b
DEC     0x00000003      decrement the top of the stack
INC     0x00000004      increment the top of the stack
ILT     0x00000005      
IEQ     0x00000006
JMP     0x00000007
JMPT    0x00000008
JMPF    0x00000009
PUSH    0x0000000A      push value to the top of the stack
AND     0x0000000B      pop a, then pop b, then push a & b
OR      0x0000000C      pop a, then pop b, then push a | b
XOR     0x0000000D      pop a, then pop b, then push a ^ b
NOT     0x0000000E      pop a, then push !a
LOAD    0x0000000F
GLOAD   0x00000010
STORE   0x00000011
GSTORE  0x00000012
PRINT   0x00000013      pop a, then print it
POP     0x00000014      pop the top of the stack
CALL    0x00000015      
RET     0x00000016      return
NOP     0x00000017      do nothing
DROP    0x00000018      drop the value on top od the stack or remove it
SWAP    0x00000019      swap the top two values in the stack
EXIT    0x0000001A      exit program
