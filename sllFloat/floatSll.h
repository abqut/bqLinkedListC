#include <stddef.h>

typedef struct _nodeFloat{
    float value;
    struct _nodeFloat* next;
} nodeFloat;

nodeFloat* initFloatSll(float* array, size_t N);

void freeFloatSll(nodeFloat* first);

void insertFloatSll(nodeFloat* first, float value, size_t index);

void deleteNodeFloatSll(nodeFloat* first, size_t index);

void swapFloatSll(nodeFloat* first, size_t firstIndex, size_t secondIndex);

float getValueFloatSll(nodeFloat* first, size_t index);

void concatFloatSll(nodeFloat* firstHead, nodeFloat* secondHead);