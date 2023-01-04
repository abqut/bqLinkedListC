#include "intSll.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

nodeInt* createIntNode(int value, nodeInt* next){
    nodeInt* result = malloc(sizeof(nodeInt));
    result->value = value;
    result->next = next;
    return result;
}

nodeInt* initIntSll(int* array, size_t N) {
    nodeInt* last = malloc(sizeof(nodeInt));
    last->value = array[N - 1];
    last->next = NULL;
    for (int i = N - 2; i >= 0; i--) {
        nodeInt* nextNode = malloc(sizeof(nodeInt));
        nextNode->value = array[i];
        nextNode->next = last;
        last = nextNode;
    }
    return last;
}

void freeIntSll(nodeInt* first) {
    nodeInt* nextN = first;
    do {
        nodeInt* nextP = nextN->next;
        free(nextN);
        nextN = nextP;
    } while (nextN != NULL);
}

void deleteNodeIntSll(nodeInt* first, size_t index) {
    nodeInt* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeInt* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size. \n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeInt* nextElement = nextNode->next;
    nodeInt* newNextElement = nextElement->next;
    nextNode->next = newNextElement;
    free(nextElement);
}

void insertIntSll(nodeInt* first, int value, size_t index) {
    nodeInt* nextNode = first;
    for (size_t i = 0; i < index - 1; i++) {
        nodeInt* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    nodeInt* nextElement = nextNode->next;
    nodeInt* element = malloc(sizeof(nodeInt));
    element->value = value;
    element->next = nextElement;
    if(nextElement != NULL){
        nextNode->next = element;
    }
}

int getValueIntSll(nodeInt* first, size_t index) {
    nodeInt* nextNode = first;
    for (size_t i = 0; i < index; i++) {
        nodeInt* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return -1;
        }
        nextNode = nextPtr;
    }
    int ret = nextNode->value;
    return (ret);
}

void swapIntSll(nodeInt* first, size_t firstIndex, size_t secondIndex) {
    nodeInt* nextNode = first;
    size_t index1 = firstIndex;
    size_t index2 = secondIndex;
    if (firstIndex > secondIndex) {
        index1 = secondIndex;
        index2 = firstIndex;
    }
    for (size_t i = 0; i < index1; i++) {
        nodeInt* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: First index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    int firstValue = nextNode->value;
    nodeInt* firstNode = nextNode;
    for (size_t j = index1; j < index2; j++) {
        nodeInt* nextPtr = nextNode->next;
        if (nextPtr == NULL) {
            fprintf(stderr, "ERROR: Second index exceeds list size.\n");
            return;
        }
        nextNode = nextPtr;
    }
    int secondValue = nextNode->value;
    nodeInt* secondNode = nextNode;
    firstNode->value = secondValue;
    secondNode->value = firstValue;
}

void concatIntSll(nodeInt* firstHead, nodeInt* secondHead) {
    nodeInt* node = firstHead;
    nodeInt* nextNode = node;
    do {
        node = nextNode;
        nextNode = node->next;
    } while (nextNode != NULL);
    node->next = secondHead;
}