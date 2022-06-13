/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

void freeQueue(LIST* queue) {
    //placeholder variables
    LIST_NODE *printJobNode, *temp;

    //traverse through the list
    for (printJobNode = queue->head; printJobNode != NULL; printJobNode=temp) {
        free(printJobNode->dataPtr);
        //store info about the next node before freeing printJobNode
        temp = printJobNode->next;
        free(printJobNode);
    }
    free(queue);
}
