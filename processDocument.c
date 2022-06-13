/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

void processDocument(LIST* queue) {
    //static variable that will hold the current printing document
    static DOCUMENT* currentDocument;

    //pop off a new print job from the queue if there is currently no printing document
    if (currentDocument == NULL && queue->head != NULL) {
        currentDocument = queue->head->dataPtr;
        LIST_NODE* temp = queue->head->next;
        //free dynamically allocated memory of the print job node
        free(queue->head);
        queue->head = temp;
        //decrement queue count after popping
        (queue->count)--;
    }

    //if there currently is a printing document, process it
    if (currentDocument != NULL) {
        //print statements
        if (DEBUG_PRINT_PROCESS)  {
            printf("PRINTING - DOCUMENT: %d \t PAGE: %d \t priority: %d\n",
                   currentDocument->docNum, currentDocument->numPages, currentDocument->priority);
        }
        //decrement numPages
        currentDocument->numPages -= PAGESPERMINUTE;
        if (currentDocument->numPages <= 0) {
            /*
            The cycle count that is outputted is the number of cycles that print
            job remained in the queue before being sent to the printer to be
            printed
            */
            printf("Print Job Completed - Document Number: %d - Cycle Count: %d\n",
                   currentDocument->docNum,
                   currentDocument->numCycles);
            free(currentDocument);
            /* explicitly setting current document pointer to null after freeing its
            allocated memory */
            currentDocument = NULL;
        }
    }
}
