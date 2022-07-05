#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "value.h"

#define STACK_MAX 256

typedef struct {
    Chunk* chunk;
    // Direct pointer to instruction, not an index value to instruction.
    uint8_t* ip;
    Value stack[STACK_MAX];
    Value* stackTop;
    Obj* objects;
} VM;

typedef enum {
    INTERPRET_OK,
    INTERPRET_COMPILE_ERROR,
    INTERPRET_RUNTIME_ERROR
} InterpretResult;

extern VM vm;

/*
 * Initialises the VM.
 */
void initVM();

/*
 * Clears the memory of the VM.
 */
void freeVM();

/*
 * Interprets a chunk of bytecode.
 */
InterpretResult interpret(const char* source);

/*
 * Pushes a value to the VM stack.
 */
void push(Value value);

/*
 * Pops a value off from the VM stack.
 */
Value pop();

#endif
