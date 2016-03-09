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

Compile
-------
first you must change the assembly into binary opcode so the vm would understand it

To compile using the compiler:

 $  ./crystal-compiler/bin/Debug/crystal-compiler filename
  
this will generate .crystal file in the test folder 

then you need to send the .crystal file to the vm To excute it: 
 $ ./crytal-vm/bin/Debug/crystal-vm out.crystal
  
Instruction set
---------------


