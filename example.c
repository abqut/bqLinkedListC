#include <stdio.h>
#include <stdlib.h>

#include "./sllInt/intSll.h"

int main() {
    int testArray[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int testArrayReversed[11] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    nodeInt* head = initIntSll(testArray, 11);
    nodeInt* headReverse = initIntSll(testArrayReversed, 11);
    
    nodeInt* nextNode = head;

    printf("Fifth value is: %d\n", getValueIntSll(head, 4));

    insertIntSll(head, 727, 7);

    deleteNodeIntSll(head, 6);

    swapIntSll(head, 8, 3);

    
    int i = 0;
    do {
        printf("testArray[%d]: %d\n", i, nextNode->value);
        nodeInt* nextP = nextNode->next;
        nextNode = nextP;
        i++;
    } while (nextNode != NULL);

    concatIntSll(head, headReverse);

    printf("Concatenated array:\n\n");
    
    nextNode = head;

    int j = 0;
    do {
        printf("testArray[%d]: %d\n", j, nextNode->value);
        nodeInt* nextP = nextNode->next;
        nextNode = nextP;
        j++;
    } while (nextNode != NULL);


    freeIntSll(head);
    return 0;
}