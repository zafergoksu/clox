#include <stdio.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static InterpretResult run() {
    // Since `ip` is a direct pointer, when we increment we access the next byte
    // of code since it's just a pointer to the code array. Since dereferencing
    // a pointer is faster, using an index to calculate an offset and access is
    // not optimal.
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op)                                                          \
    do {                                                                       \
        double b = pop();                                                      \
        double a = pop();                                                      \
        push(a op b);                                                          \
    } while (false)

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        printf("\t\t\t");
        for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        /*
         * Since `ip` is a direct pointer (this points to the bytecode
         * instruction), we do pointer arithmetic to point to the index offset.
         * E.g.: vm.ip = 0x3255 or something like so, vm.chunk->code = 0x3252
         * vm.ip - vm.chunk->code = 3, an offset of 3 for when we access the
         * code array.
         */
        disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
        case OP_CONSTANT: {
            Value constant = READ_CONSTANT();
            push(constant);
            break;
        }
        case OP_ADD: {
            BINARY_OP(+);
            break;
        }
        case OP_SUBTRACT: {
            BINARY_OP(-);
            break;
        }
        case OP_MULTIPLY: {
            BINARY_OP(*);
            break;
        }
        case OP_DIVIDE: {
            BINARY_OP(/);
            break;
        }
        case OP_NEGATE: {
            push(-pop());
            break;
        }
        case OP_RETURN: {
            printValue(pop());
            printf("\n");
            return INTERPRET_OK;
        }
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

static void resetStack() {
    // `stackTop` is a direct pointer of the next available space in the VM
    // stack.
    vm.stackTop = vm.stack;
}

void initVM() {
    resetStack();
}

void freeVM() {}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--;
    return *vm.stackTop;
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}
