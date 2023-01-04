#include <stddef.h>

typedef struct _nodeChar{
    char value;
    struct _nodeChar* next;
} nodeChar;

nodeChar* createCharNode(char value, nodeChar* next);

nodeChar* initCharSll(char* array, size_t N);

void freeCharSll(nodeChar* first);

void insertCharSll(nodeChar* first, char value, size_t index);

void deleteNodeCharSll(nodeChar* first, size_t index);

void swapCharSll(nodeChar* first, size_t firstIndex, size_t secondIndex);

char getValueCharSll(nodeChar* first, size_t index);

void concatCharSll(nodeChar* firstHead, nodeChar* secondHead);