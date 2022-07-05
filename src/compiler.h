#ifndef clox_compiler_h
#define clox_compiler_h

#include "object.h"
#include "vm.h"

/*
 * Compiles the given source code into clox bytecode.
 *
 * @param const char* source the pointer to the source string.
 */
bool compile(const char* source, Chunk* chunk);

#endif
