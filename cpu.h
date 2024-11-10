#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1024
#define NUM_REGISTERS 11

typedef struct CPU {
    unsigned short registers[NUM_REGISTERS];
    unsigned char memory[MEMORY_SIZE];
    unsigned short pc;
    unsigned short ir;
    unsigned char flags;
} CPU;

// Define Opcodes
enum Opcodes { MOV = 0x3, ADD = 0x1, SUB = 0x4, MUL = 0x5, LD = 0x7, ST = 0x8, JMP = 0x9, CMP = 0x8, HLT = 0xA, CALL = 0xB, RET = 0xC };

// Function prototypes
void initializeCPU(CPU *cpu);

#endif // CPU_H
