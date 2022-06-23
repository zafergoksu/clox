#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/*
 * Operation Codes
 */
typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

/*
 * Dynamic array of instructions
 */
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int *lines;
    ValueArray constants;
} Chunk;

/*
 * Initialise the code chunk.
 *
 * @param Chunk *chunk the chunk being pointed to.
 */
void initChunk(Chunk *chunk);

/*
 * Free the code chunk.
 *
 * @param Chunk *chunk the chunk to be freed.
 */
void freeChunk(Chunk *chunk);

/*
 * Append a byte to the end of the chunk.
 *
 * @param Chunk *chunk chunk to be appended to.
 * @param uint8_t byte the byte opcode that is being appended.
 * @param int line the line number that the instruction is at.
 */
void writeChunk(Chunk *chunk, uint8_t byte, int line);

/*
 * Convenience method to add a constant to constant-pool.
 *
 * @param Chunk *chunk the bytecode chunk to add a new constant to.
 * @param Value value the new value to add.
 */
int addConstant(Chunk *chunk, Value value);

#endif
