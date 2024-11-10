#include "execute.h"
#include "display.h"

void executeProgram(CPU *cpu) {
    while (1) {
        cpu->ir = cpu->memory[cpu->pc++];

        unsigned char opcode = (cpu->ir >> 12) & 0xF;
        unsigned char dest = (cpu->ir >> 8) & 0xF;
        unsigned char src = (cpu->ir >> 4) & 0xF;
        unsigned char imm = cpu->ir & 0xF;

        switch (opcode) {
            case MOV:
                cpu->registers[dest] = imm;
                break;
            case ADD:
                cpu->registers[dest] += cpu->registers[src];
                break;
            case SUB:
                cpu->registers[dest] -= cpu->registers[src];
                break;
            case MUL:
                cpu->registers[dest] *= cpu->registers[src];
                break;
            case CMP:
                cpu->flags = (cpu->registers[dest] == cpu->registers[src]) ? 1 : 0;
                break;
            case CALL:
                cpu->registers[10] = cpu->pc;
                cpu->pc = imm;
                break;
            case RET:
                cpu->pc = cpu->registers[10];
                break;
            case HLT:
                return;
            default:
                printf("Unknown instruction\n");
                return;
        }

        displayMemorySegments(cpu);
    }
}
