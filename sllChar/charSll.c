#include "charSll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

nodeChar* initCharSll(char* array, size_t N) {
    nodeChar* last = malloc(sizeof(nodeChar));
    last->value = array[N - 1];
    last->next = NULL;
    for (int i = N - 2; i >= 0; i--) {
        nodeChar* nextNode = malloc(sizeof(nodeChar));
        nextNode->value = array[i];
        nextNode->next = last;
        last = nextNode;
    }
    return last;
}

void freeCharSll(nodeChar* first) {
    nodeChar* nextN = first;
    do {
        nodeChar* nextP = nextN->next;
        free(nextN);
        nextN = nextP;
    } while (nextN != NULL);
}

void deleteNodeCharSll(nodeChar* first, size_t index) {
    nodeChar* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeChar* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size. \n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeChar* nextElement = nextNode->next;
    nodeChar* newNextElement = nextElement->next;
    nextNode->next = newNextElement;
    free(nextElement);
}

void insertCharSll(nodeChar* first, char value, size_t index) {
    nodeChar* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeChar* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeChar* nextElement = nextNode->next;
    nodeChar* element = malloc(sizeof(nodeChar));
    element->value = value;
    element->next = nextElement;
    nextNode->next = element;
}

char getValueCharSll(nodeChar* first, size_t index) {
    nodeChar* nextNode = first;
    for (size_t i = 0; i < index; i++) {
        nodeChar* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return -1;
        }
        nextNode = nextPtr;
    }
    char ret = nextNode->value;
    return (ret);
}

void swapCharSll(nodeChar* first, size_t firstIndex, size_t secondIndex) {
    nodeChar* nextNode = first;
    size_t index1 = firstIndex;
    size_t index2 = secondIndex;
    if (firstIndex > secondIndex) {
        index1 = secondIndex;
        index2 = firstIndex;
    }
    for (size_t i = 0; i < index1; i++) {
        nodeChar* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    char firstValue = nextNode->value;
    nodeChar* firstNode = nextNode;
    for (size_t j = index1; j < index2; j++) {
        nodeChar* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Second index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    char secondValue = nextNode->value;
    nodeChar* secondNode = nextNode;
    firstNode->value = secondValue;
    secondNode->value = firstValue;
}

void concatCharSll(nodeChar* firstHead, nodeChar* secondHead) {
    nodeChar* node = firstHead;
    nodeChar* nextNode = node;
    do {
        node = nextNode;
        nextNode = node->next;
    } while (nextNode != NULL);
    node->next = secondHead;
}