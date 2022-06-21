#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"

/*
 * Operation Codes
 */
typedef enum {
    OP_RETURN,
} OpCode;

/*
 * Dynamic array of instructions
 */
typedef struct {
    int count;
    int capacity;
    uint8_t *code;
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
 */
void writeChunk(Chunk *chunk, uint8_t byte);

#endif
