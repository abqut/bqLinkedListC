#include "doubleSll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

nodeDouble* initDoubleSll(double* array, size_t N) {
    nodeDouble* last = malloc(sizeof(nodeDouble));
    last->value = array[N - 1];
    last->next = NULL;
    for (int i = N - 2; i >= 0; i--) {
        nodeDouble* nextNode = malloc(sizeof(nodeDouble));
        nextNode->value = array[i];
        nextNode->next = last;
        last = nextNode;
    }
    return last;
}

void freeDoubleSll(nodeDouble* first) {
    nodeDouble* nextN = first;
    do {
        nodeDouble* nextP = nextN->next;
        free(nextN);
        nextN = nextP;
    } while (nextN != NULL);
}

void deleteNodeDoubleSll(nodeDouble* first, size_t index) {
    nodeDouble* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeDouble* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size. \n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeDouble* nextElement = nextNode->next;
    nodeDouble* newNextElement = nextElement->next;
    nextNode->next = newNextElement;
    free(nextElement);
}

void insertDoubleSll(nodeDouble* first, double value, size_t index) {
    nodeDouble* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeDouble* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeDouble* nextElement = nextNode->next;
    nodeDouble* element = malloc(sizeof(nodeDouble));
    element->value = value;
    element->next = nextElement;
    nextNode->next = element;
}

double getValueDoubleSll(nodeDouble* first, size_t index) {
    nodeDouble* nextNode = first;
    for (size_t i = 0; i < index; i++) {
        nodeDouble* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return -1;
        }
        nextNode = nextPtr;
    }
    double ret = nextNode->value;
    return (ret);
}

void swapDoubleSll(nodeDouble* first, size_t firstIndex, size_t secondIndex) {
    nodeDouble* nextNode = first;
    size_t index1 = firstIndex;
    size_t index2 = secondIndex;
    if (firstIndex > secondIndex) {
        index1 = secondIndex;
        index2 = firstIndex;
    }
    for (size_t i = 0; i < index1; i++) {
        nodeDouble* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    double firstValue = nextNode->value;
    nodeDouble* firstNode = nextNode;
    for (size_t j = index1; j < index2; j++) {
        nodeDouble* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Second index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    double secondValue = nextNode->value;
    nodeDouble* secondNode = nextNode;
    firstNode->value = secondValue;
    secondNode->value = firstValue;
}

void concatDoubleSll(nodeDouble* firstHead, nodeDouble* secondHead) {
    nodeDouble* node = firstHead;
    nodeDouble* nextNode = node;
    do {
        node = nextNode;
        nextNode = node->next;
    } while (nextNode != NULL);
    node->next = secondHead;
}