/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

void printQueue(LIST* queue) {
    if (queue->count == 0) {
        printf("EMPTY QUEUE - no print jobs currently in queue\n\n");
    } else {
        printf("Current Printer Queue Size: %d\n", queue->count);
        //iterate through the queue
        for (LIST_NODE* curNode = queue->head; curNode != NULL; curNode=curNode->next) {
            printf("Current Printer Queue : DocNum: %d \t NumofPages %d \t PriorityLevel %d \t NumOfCycles %d\n",
                   curNode->dataPtr->docNum,
                   curNode->dataPtr->numPages,
                   curNode->dataPtr->priority,
                   curNode->dataPtr->numCycles);
        }
        printf("END OF LIST\n\n");
    }
}
