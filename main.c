/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

int main() {
    /* required so the rand() function is able to produce a new set of random numbers
    every time it is called */
    srand(time(NULL));

    LIST* queue; //main control structure
    //placeholder variables
    DOCUMENT* document;
    LIST_NODE *printJobNode;

    //used to exit the program
    char c = (char) 0;

    queue = (LIST*)malloc(sizeof(LIST));
    //explicitly stating these values to prevent any errors in code
    queue->head = NULL;
    queue->count = 0;

    //main loop
    for (int i = 0; i < ITERATIONS; i++) {
        if (DEBUG_LIST) {
            printQueue(queue);
        }

        //creating print job
        document = createPrintJob();

        //if document is created, create its associated node and add it to the queue
        if (document) {
            printJobNode = (LIST_NODE*)malloc(sizeof(LIST_NODE));
            printJobNode->dataPtr = document;
            addPrintJob(queue, printJobNode);
        }

        //print the active print job of the queue
        processDocument(queue);
        //increase the cycle count of each print job in the queue
        incrementCycleCount(queue);


    }

    //OUTRO
    printf("\n\n.End of Program - * DHRUV N. PATEL *\n");
    printf("Number of print jobs left in the queue: %d\n\n", queue->count);
    printf("(Enter any key then <Enter> to quit): ");
    scanf("%c", &c);

    //freeing all the dynamically allocated memory used in this program
    /*freeing this queue will also automatically free the document and printJobNode
    variables as well*/
    freeQueue(queue);

    return 0;
}
