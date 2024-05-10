#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct String {
    int size;
    char string[100];
} String;


void read_csv(char* filename) {
    FILE* fptr;

    // Open a file in read mode
    fptr = fopen(filename, "r");

    // Store the content of the file
    char myString[100];

    while (fgets(myString, 100, fptr)) {
        char** row = calloc(10, sizeof(char *));
        char* token = strtok(myString, " ");
        // loop through the string to extract all other tokens
        int i = 0;
        while (token != NULL) {
            printf(" %s\n", token); //printing each token
            token = strtok(NULL, " ");
            row[i++] = token;
        }




    }

    // Close the file
    fclose(fptr);
}


int main() {
    read_csv("/Users/georgerahul/Desktop/DBMS Lab/Assignment 1/C/instructor.txt");
    return 0;
}
