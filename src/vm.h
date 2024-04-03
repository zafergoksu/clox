#ifndef clox_vm_h
#define clox_vm_h

#include "chunk.h"
#include "object.h"
#include "table.h"
#include "value.h"

#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
    ObjClosure* closure;
    // Direct pointer to instruction, not an index value to instruction.
    uint8_t* ip;
    Value* slots;
} CallFrame;

typedef struct {
    CallFrame frames[FRAMES_MAX];
    int frameCount;
    Value stack[STACK_MAX];
    Value* stackTop;
    Table globals;
    Table strings;
    ObjString* initString;
    ObjUpvalue* openUpvalues;

    size_t bytesAllocated;
    size_t nextGC;
    Obj* objects;
    int grayCount;
    int grayCapacity;
    Obj** grayStack;
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
void initVM(void);

/*
 * Clears the memory of the VM.
 */
void freeVM(void);

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
Value pop(void);

#endif
