#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"
#include "object.h"

#define ALLOCATE(type, count) (type*)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)

#define GROW_ARRAY(type, pointer, oldCount, newCount)                          \
    (type*)reallocate(pointer, sizeof(type) * (oldCount),                      \
                      sizeof(type) * (newCount))

#define FREE_ARRAY(type, pointer, oldCount)                                    \
    reallocate(pointer, sizeof(type) * (oldCount), 0)

/*
 * Reallocate chunk by the pointer size and new capacity.
 *
 * @param void *pointer the pointer type.
 * @param size_t oldSize the old size of the chunk.
 * @param size_t newSize the new size of the chunk.
 */
void* reallocate(void* pointer, size_t oldSize, size_t newSize);
void markObject(Obj* obj);
void markValue(Value value);
void collectGarbage(void);
void freeObjects(void);

#endif
