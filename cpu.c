#include "cpu.h"

// Helper function to initialize the CPU
void initializeCPU(CPU *cpu) {
    cpu->pc = 0;
    cpu->ir = 0;
    cpu->flags = 0;
    for (int i = 0; i < NUM_REGISTERS; i++) {
        cpu->registers[i] = 0;
    }
    for (int i = 0; i < MEMORY_SIZE; i++) {
        cpu->memory[i] = 0;
    }
}

// Function to load the program from a text file into memory
void loadProgramFromFile(CPU *cpu, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }

    unsigned short instruction;
    int address = 0;
    while (fscanf(file, "%hx", &instruction) != EOF) {
        if (address < MEMORY_SIZE) {
            cpu->memory[address++] = instruction;
        } else {
            printf("Memory overflow\n");
            break;
        }
    }

    fclose(file);
}

// Display memory layout in a segmented format
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
