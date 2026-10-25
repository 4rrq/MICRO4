# MICRO4: 4-Bit CPU and Memory Emulator

A minimal 4-bit CPU and 16-slot RAM architecture built in C++.

## Specifications

* Registers: 4 independent unsigned 4-bit registers (A, B, N, V).
* RAM: 16 addressable memory slots (0 to 15).
* Constraints: Values are strictly locked to a 4-bit unsigned boundary (0 to 15) using bitwise masking (`& 15`).

## Instruction Set

* `ADD reg1, reg2` - Adds reg2 to reg1 (wraps around on overflow: e.g., 12 + 6 = 2).
* `SUB reg1, reg2` - Subtracts reg2 from reg1 (wraps around on underflow: e.g., 0 - 7 = 9).
* `MOV reg1, reg2` - Copies reg2 into reg1, then clears reg2 to 0.
* `STORE reg, slot` - Writes a register value into a RAM slot.
* `LOAD reg, slot` - Loads a RAM slot value into a register.

## How to Run

Compile with Clang:
```bash
clang++ -std=c++20 CPU.cpp -o MICRO4
./MICRO
```
