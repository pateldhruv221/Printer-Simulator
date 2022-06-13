/* CS1037a 2021 */
/* Assignment 05 */
/* Dhruv N. Patel */
/* 251155532 */
/* dpate449 */
/* Nov. 29th, 2021 */

#include "headers.h"

DOCUMENT* createPrintJob() {
    //placeholder variable
    DOCUMENT* document = NULL;

    int probability = 0;

    //generating random number between 1 and 100 inclusive
    probability = (rand()%100)+1;
    //create a new print job if probability is between 1 and 10 inclusive
    //do not need to have probability >= 1 because all probabilities will satisfy this condition
    if (probability <= 10) {
        document = (DOCUMENT*)malloc(sizeof(DOCUMENT));
        //generate a new probability, this time for determining the priority of the print job
        probability = (rand()%100)+1;
        if (probability >= 81) {
            document->priority = 3;
        } else if (probability >= 11) {
            document->priority = 2;
        } else {
            document->priority = 1;
        }
        //generating a random number for the number of pages of the print job
        document->numPages = (rand()%MAXPAGES)+1;

        //initially the number of cycles of the print job is set to 0
        document->numCycles = 0;

    }

    return document;

}
