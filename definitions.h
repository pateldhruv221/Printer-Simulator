/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#ifndef DEFINITIONS_H_INCLUDED
    #define DEFINITIONS_H_INCLUDED

    //number of iterations the code will run for
    #define ITERATIONS 1000
    //upper limit of how many pages can exist for a print job
    #define MAXPAGES 30
    // what to decrement the current active print job's number of pages property by
    #define PAGESPERMINUTE 1
    // limit for the number of cycles a document has been in the queue for
    #define MAXCYCLES 200

    //-----------------DEBUG STATEMENTS-----------------
    //print queue
    #define DEBUG_LIST 0
    //print new print job generated
    #define DEBUG_ADDING 0
    //print out document that is being printed
    #define DEBUG_PRINT_PROCESS 0
    //print out queue after the cycles have been incremented
    #define DEBUG_SHOW_CYCLES 0
    //print if a print job has exceeded the max number of cycles
    #define DEBUG_SHOW_EXCEEDED 0

    //-----------------TYPE DEFINITIONS-----------------
    //DOCUMENT
    typedef struct document {
        int docNum;
        int priority;
        int numPages;
        int numCycles;
    } DOCUMENT;

    //PRINT JOB NODE
    typedef struct node {
        DOCUMENT* dataPtr;
        struct node* next;
    } LIST_NODE;

    //PRINT QUEUE
    typedef struct list {
        LIST_NODE* head;
        int count;
    } LIST;

    //-----------------FUNCTION PROTOTYPES-----------------

    void addPrintJob(LIST*, LIST_NODE*);
    DOCUMENT* createPrintJob();
    void incrementCycleCount(LIST*);
    void printQueue(LIST*);
    void processDocument(LIST*);
    void freeQueue(LIST*);

#endif // DEFINITIONS_H_INCLUDED
