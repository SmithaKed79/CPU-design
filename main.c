#include "cpu.h"
#include "memory.h"
#include "execute.h"
#include "loading.h"

int main() {
    CPU cpu;
    initializeCPU(&cpu);

    loadProgramFromFile(&cpu, "program.txt");

    executeProgram(&cpu);

    return 0;
}
