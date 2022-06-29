#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"
#include "value.h"

/*
 * Disassemble bytecode chunk with a name.
 *
 * @param Chunk *chunk the chunk to be disassembled.
 * @param const char *name the name of the chunk being disassembled.
 */
void disassembleChunk(Chunk* chunk, const char* name);

/*
 * Disassemble a specific bytecode instruction.
 *
 * @param Chunk *chunk the chunk that contains the instruction to be
 * disassembled.
 * @param int offset the offset required to find the instruction in the bytecode
 * chunk.
 */
int disassembleInstruction(Chunk* chunk, int offset);

#endif
