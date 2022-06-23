#ifndef clox_value_h
#define clox_value_h

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value *values;
} ValueArray;

/*
 * Initialises a ValueArray.
 *
 * @param ValueArray *array the ValueArray to be initialised.
 */
void initValueArray(ValueArray *array);

/*
 * Writes to a ValueArray.
 *
 * @param ValueArray *array the ValueArray to be written to.
 */
void writeValueArray(ValueArray *array, Value value);

/*
 * Frees the ValueArray.
 *
 * @param ValueArray *array the ValueArray that is to be freed.
 */
void freeValueArray(ValueArray *array);

/*
 * Prints the value.
 *
 * @Param Value value the value to be printed.
 */
void printValue(Value value);

#endif
