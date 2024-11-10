#include "loading.h"
#include "memory.h"

void load_program(const char *filename) {
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