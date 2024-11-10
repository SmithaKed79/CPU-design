#include "display.h"

void displayMemorySegments(CPU *cpu) {
    printf("\nMemory Segments:\n");

    printf("Program Segment:\n");
    for (int i = 0; i < 64; i++) {
        printf("%02X ", cpu->memory[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("\nData Segment:\n");
    for (int i = 64; i < 128; i++) {
        printf("%02X ", cpu->memory[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("\nStack Segment:\n");
    for (int i = 128; i < 256; i++) {
        printf("%02X ", cpu->memory[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }

    printf("\nRegisters:\n");
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("R%d: %04X ", i, cpu->registers[i]);
        if ((i + 1) % 4 == 0) printf("\n");
    }

    printf("\n");
}
