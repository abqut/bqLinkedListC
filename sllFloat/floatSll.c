#include "floatSll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

nodeFloat* initFloatSll(float* array, size_t N) {
    nodeFloat* last = malloc(sizeof(nodeFloat));
    last->value = array[N - 1];
    last->next = NULL;
    for (int i = N - 2; i >= 0; i--) {
        nodeFloat* nextNode = malloc(sizeof(nodeFloat));
        nextNode->value = array[i];
        nextNode->next = last;
        last = nextNode;
    }
    return last;
}

void freeFloatSll(nodeFloat* first) {
    nodeFloat* nextN = first;
    do {
        nodeFloat* nextP = nextN->next;
        free(nextN);
        nextN = nextP;
    } while (nextN != NULL);
}

void deleteNodeFloatSll(nodeFloat* first, size_t index) {
    nodeFloat* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeFloat* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size. \n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeFloat* nextElement = nextNode->next;
    nodeFloat* newNextElement = nextElement->next;
    nextNode->next = newNextElement;
    free(nextElement);
}

void insertFloatSll(nodeFloat* first, float value, size_t index) {
    nodeFloat* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeFloat* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeFloat* nextElement = nextNode->next;
    nodeFloat* element = malloc(sizeof(nodeFloat));
    element->value = value;
    element->next = nextElement;
    nextNode->next = element;
}

float getValueFloatSll(nodeFloat* first, size_t index) {
    nodeFloat* nextNode = first;
    for (size_t i = 0; i < index; i++) {
        nodeFloat* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return -1;
        }
        nextNode = nextPtr;
    }
    float ret = nextNode->value;
    return (ret);
}

void swapFloatSll(nodeFloat* first, size_t firstIndex, size_t secondIndex) {
    nodeFloat* nextNode = first;
    size_t index1 = firstIndex;
    size_t index2 = secondIndex;
    if (firstIndex > secondIndex) {
        index1 = secondIndex;
        index2 = firstIndex;
    }
    for (size_t i = 0; i < index1; i++) {
        nodeFloat* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    float firstValue = nextNode->value;
    nodeFloat* firstNode = nextNode;
    for (size_t j = index1; j < index2; j++) {
        nodeFloat* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Second index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    float secondValue = nextNode->value;
    nodeFloat* secondNode = nextNode;
    firstNode->value = secondValue;
    secondNode->value = firstValue;
}

void concatFloatSll(nodeFloat* firstHead, nodeFloat* secondHead) {
    nodeFloat* node = firstHead;
    nodeFloat* nextNode = node;
    do {
        node = nextNode;
        nextNode = node->next;
    } while (nextNode != NULL);
    node->next = secondHead;
}
