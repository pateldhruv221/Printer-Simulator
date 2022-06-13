/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

void incrementCycleCount(LIST* queue) {
    //iterate through the queue
    for (LIST_NODE* curNode = queue->head; curNode != NULL; curNode=curNode->next) {
        //increase the cycles of each document
        (curNode->dataPtr->numCycles)++;
        //print statements
        if (DEBUG_SHOW_CYCLES) {
            printf("Increment Cycle - Document: %d \t Pages: %d \t Priority: %d \t Cycle Count: %d\n",
                   curNode->dataPtr->docNum,
                   curNode->dataPtr->numPages,
                   curNode->dataPtr->priority,
                   curNode->dataPtr->numCycles);
        }
        //show a print job node if its num cycles has been exceeded
        if (curNode->dataPtr->numCycles == MAXCYCLES && DEBUG_SHOW_EXCEEDED == 1) {
            printf("EXCEEDED CYCLE COUNT - Document: %d \t Pages: %d \t Priority:%d \t Cycle Count:%d\n",
                   curNode->dataPtr->docNum,
                   curNode->dataPtr->numPages,
                   curNode->dataPtr->priority,
                   curNode->dataPtr->numCycles);
        }
    }

    //formatting
    if (DEBUG_PRINT_PROCESS && DEBUG_SHOW_EXCEEDED)
        printf("\n\n");
}
