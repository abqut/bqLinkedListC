#include <stddef.h>

typedef struct _nodeInt{
    int value;
    struct _nodeInt* next;
} nodeInt;

nodeInt* initIntSll(int* array, size_t N);

void freeIntSll(nodeInt* first);

void insertIntSll(nodeInt* first, int value, size_t index);

void deleteNodeIntSll(nodeInt* first, size_t index);

void swapIntSll(nodeInt* first, size_t firstIndex, size_t secondIndex);

int getValueIntSll(nodeInt* first, size_t index);

void concatIntSll(nodeInt* firstHead, nodeInt* secondHead);