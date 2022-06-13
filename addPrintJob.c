/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

void addPrintJob(LIST *list, LIST_NODE* printJobNode) {
    //static variable to hold the current docNum
    static int docNum = 1;

    //set the document's doc number before adding to the list
    /* the docNum isn't set to the count of the list because this number changes
    every time a print job is removed from the queue as well, setting this to be
    the docNum could result in more than 1 document having the same docNum */
    printJobNode->dataPtr->docNum = docNum++;

    (list->count)++;


    if (DEBUG_ADDING) {
        printf("Adding to Queue - Doc: %d \t NoPages: %d \t Priority: %d\n",
                printJobNode->dataPtr->docNum,
                printJobNode->dataPtr->numPages,
                printJobNode->dataPtr->priority);
    }

    //placeholder variables
    LIST_NODE *currentNode = NULL, *temp = NULL;

    if (list->head == NULL) { //nothing is in the queue yet
        list->head = printJobNode;
        printJobNode->next = NULL;
    }
    else if (list->head->next == NULL) { //only 1 element in the queue
        //priority of print job is greater, put it to the right
        if (printJobNode->dataPtr->priority > list->head->dataPtr->priority) {
            list->head->next = printJobNode;
            printJobNode->next = NULL;
        }
        //priority of the print job is the same, compare number of pages
        else if (printJobNode->dataPtr->priority == list->head->dataPtr->priority) {
            //put print job to the left
            if (printJobNode->dataPtr->numPages < list->head->dataPtr->numPages) {
                temp = list->head;
                list->head = printJobNode;
                printJobNode->next = temp;
                temp->next = NULL;
            }
            //numPages is the same or greater, put print job to the right
            else {
                list->head->next = printJobNode;
                printJobNode->next = NULL;
            }
        }
        //priority of the print job is less, put it to the left
        else {
            temp = list->head;
            list->head = printJobNode;
            printJobNode->next = temp;
            temp->next = NULL;
        }
    }
    else { //queue is non-empty and has more than 1 element initially
        //variable used to identify the status of the loop
        /*
        1 -> reached end of the list OR print job is the first item in the queue
            with its priority
        2 -> there already exists another print job in the queue with the same priority
             as the print job we are aiming to add to the queue
        */

        int traverseComplete = 0;

        //node to start looping from
        currentNode = list->head;
        do {
            if (currentNode == NULL) { //reached the end of the list
                traverseComplete = 1;
            }
            //only attempt to access currentNode->dataPtr->priority if currentNode is not null
            else if (printJobNode->dataPtr->priority < currentNode->dataPtr->priority) {
                traverseComplete = 1; //print job is the first item in the queue with its priority
            }
            else if (printJobNode->dataPtr->priority == currentNode->dataPtr->priority) {
                traverseComplete = 2; //items already exist in the queue with the same priority
            }
            else {
                //traverse through the loop
                temp = currentNode;
                currentNode=currentNode->next;
            }
        } while (traverseComplete == 0);

        if (traverseComplete == 1) {
            if (currentNode == list->head) {//first node in the queue
                list->head = printJobNode;
                printJobNode->next = currentNode;
            } else if (currentNode == NULL) { //last node in the queue
                temp->next = printJobNode;
                printJobNode->next = NULL;
            } else { //currentNode is in the middle of the queue
                //print job is placed before the currentNode
                printJobNode->next = currentNode;
                temp->next = printJobNode;
            }
        }
        else if (traverseComplete == 2) {
            //similar do-while loop to above to compare page numbers

            //resetting variables
            traverseComplete = 0;
            //temp = currentNode;
            do {
                //reached the end of the list OR reached the end of the same priority section
                if (currentNode == NULL ||
                    printJobNode->dataPtr->priority < currentNode->dataPtr->priority) {
                    traverseComplete = 1;
                }
                //only attempt to access currentNode->dataPtr->priority if currentNode is not null
                else if (printJobNode->dataPtr->numPages < currentNode->dataPtr->numPages) {
                    traverseComplete = 1; //print job is the first item in the queue with its page number
                }
                else {
                    temp = currentNode;
                    currentNode=currentNode->next;
                }
            } while (traverseComplete == 0);

            //similar code to above to insert the print job node based on its page numbers
            if (currentNode == list->head) {//first node in the queue
                list->head = printJobNode;
                printJobNode->next = currentNode;
            } else if (currentNode == NULL) { //last node in the queue
                temp->next = printJobNode;
                printJobNode->next = NULL;
            } else { //currentNode is in the middle of the queue
                //print job is placed before the currentNode
                printJobNode->next = currentNode;
                temp->next = printJobNode;
            }
        }

    }

}
