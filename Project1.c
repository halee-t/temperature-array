/*
Halee Tisler
Submission for Project 1
Create an array of temperature readings, populate it, and search for a specific temperature from input
*/

#include <stdio.h>                                      //standard input output
#include <stdlib.h>                                     //needed for the random number generator

void searchArray(int *);                                //Function prototype
void again();                                           //Function prototype

int main() {
    int tempReading[250];                               //array declaration of size 250 to hold data for temperature readings
    
    for (int i = 0; i < 250; i++) {                     //populate the array with random numbers 0-86 to fill up the size of the array
        tempReading[i] = rand() % 86;
    }

    searchArray(tempReading);                           //call upon the searchArray function, send the tempReading array by reference
    
}

void searchArray(int * tempReading) {
    printf("What temperature would you like to search for?\n");

    int tempSearch;
    scanf("%d", &tempSearch);                           //scans input for the temperature the user would like to search, the & passes the variable by value

    int numOccured = 0;                                 //this will track the number of times that the for loop detects a matching temperature

    for (int i=0; i < 250; i++) {                       /*this for loop will go through each index of tempReading and determine if tempSearch
                                                          matches the data in that index of tempReading. If it does, increase the counter for occurences */
        if (tempSearch == tempReading[i]) {             
            numOccured += 1;
        }
    }

    if (numOccured == 1) {                              //this is to account for the singular version of time instead of it saying "1 times"

        printf("The temperature you are searching for is present in the data! \n");
        printf("The temperature was recorded as %d degrees %d time during the Fall semester. \n", tempSearch, numOccured);
    }

    else if (numOccured > 1) {                           //if the counter if greater than 0, a match was found, tell the user it is present and how many times it occured

        printf("The temperature you are searching for is present in the data! \n");
        printf("The temperature was recorded as %d degrees %d times during the Fall semester. \n", tempSearch, numOccured);
    }

    else if (numOccured == 0) {                         //if the number of occurences is zero, inform the user the desired temperature is not present in the data
        printf("The temperature you are searching for is not present in the data. \n");
    }

    again();

}

void again() {
    //This is just for fun, allows you to go back to the main function if you want to look for another temp instead of executing the file again in the terminal

    printf("\nWould you like to search for another value? Enter 1 for yes, 0 for no:\n");
    int again;
    scanf("%d", &again);

    if(again == 0) {
        printf("Goodbye!\n");
    }

    else if(again == 1) {
        printf("\n");
        main();
    }

    else {
        printf("You have entered an invalid number. Please enter 1 for yes, or 0 for no: \n");
    }
}