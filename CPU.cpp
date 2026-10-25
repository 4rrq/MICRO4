#include <iostream>
#include <string>

struct Memory {
    int slots[16] = {0};
};

struct CPU {
    unsigned int registers[4] = {0};

    int get_index(char reg) {
        if (reg == 'A') return 0;
        if (reg == 'B') return 1;
        if (reg == 'N') return 2;
        if (reg == 'V') return 3;
        return -1; 
    }

    void ADD(char reg1, char reg2){
        int indexOne = get_index(reg1);
        int indexTwo = get_index(reg2);

        int result = (registers[indexOne] + registers[indexTwo]) & 15;

        registers[indexOne] = result;
    }

    void MOV(char reg1, char reg2){
        int indexOne = get_index(reg1);
        int indexTwo = get_index(reg2);

        registers[indexOne] = registers[indexTwo];

        registers[indexTwo] = 0;
    }

    void SUB(char reg1, char reg2){
        int indexOne = get_index(reg1);
        int indexTwo = get_index(reg2);

        unsigned int result = (registers[indexOne] - registers[indexTwo]) & 15;

        registers[indexOne] = result;
    }

    void RESULT(){
        std::cout << "A: " << registers[0] 
                << " B: " << registers[1] 
                << " N: " << registers[2] 
                << " V: " << registers[3] << '\n';
    }

    void STORE(Memory& mem, char reg, int slot){
        int registerIndex = get_index(reg);

        if(slot >= 0 && slot < 16 && registerIndex != -1) {
            mem.slots[slot] = registers[registerIndex];
        }
    }

    void LOAD(Memory& mem, char reg, int slot){
        int registerIndex = get_index(reg);
        if(slot >= 0 && slot < 16 && registerIndex != -1){
            registers[registerIndex] = mem.slots[slot] & 15;
        }
    }
};

int main(){
    CPU cpu;
    Memory mem;

    cpu.registers[0] = 12;
    cpu.registers[1] = 6;

    cpu.ADD('A', 'B');

    cpu.STORE(mem, 'A', 7);
    std::cout << mem.slots[7] << '\n';
    
    cpu.RESULT();

    return 0;
}