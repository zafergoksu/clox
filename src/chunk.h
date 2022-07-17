#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/*
 * Operation Codes
 */
typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_UPVALUE,
    OP_SET_UPVALUE,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP,
    OP_JUMP_IF_FALSE,
    OP_LOOP,
    OP_CALL,
    OP_CLOSURE,
    OP_CLOSE_UPVALUE,
    OP_RETURN,
} OpCode;

/*
 * Dynamic array of instructions
 */
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    int* lines;
    ValueArray constants;
} Chunk;

/*
 * Initialise the code chunk.
 *
 * @param Chunk *chunk the chunk being pointed to.
 */
void initChunk(Chunk* chunk);

/*
 * Free the code chunk.
 *
 * @param Chunk *chunk the chunk to be freed.
 */
void freeChunk(Chunk* chunk);

/*
 * Append a byte to the end of the chunk.
 *
 * @param Chunk *chunk chunk to be appended to.
 * @param uint8_t byte the byte opcode that is being appended.
 * @param int line the line number that the instruction is at.
 */
void writeChunk(Chunk* chunk, uint8_t byte, int line);

/*
 * Convenience method to add a constant to constant-pool.
 *
 * @param Chunk *chunk the bytecode chunk to add a new constant to.
 * @param Value value the new value to add.
 * @returns int returns the current constant pool count.
 */
int addConstant(Chunk* chunk, Value value);

#endif
