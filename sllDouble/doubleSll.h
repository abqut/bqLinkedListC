#include <stddef.h>

typedef struct _nodeDouble{
    double value;
    struct _nodeDouble* next;
} nodeDouble;

nodeDouble* initDoubleSll(double* array, size_t N);

void freeDoubleSll(nodeDouble* first);

void insertDoubleSll(nodeDouble* first, double value, size_t index);

void deleteNodeDoubleSll(nodeDouble* first, size_t index);

void swapDoubleSll(nodeDouble* first, size_t firstIndex, size_t secondIndex);

double getValueDoubleSll(nodeDouble* first, size_t index);

void concatDoubleSll(nodeDouble* firstHead, nodeDouble* secondHead);