//
// Created by Vishal Rohra & Paul Whatever.
// Assign0: Pointer Sorter
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static int stringCompare (const void * a, const void * b) {
    return strcmp (*(const char **) a, *(const char **) b);
}
static int error() {
    printf("You should have only one argument\n");
    return 1;
}
int main (int argc, char * argv[]) {
    if(argc>2) {
        return error();
    }
    int x = 0, elementCount = 0, stringLength = strlen(argv[1]);
    char *input = (char *)malloc(stringLength);
    char *string = strtok (argv[1], " ,./;'`\"[]1234567890-=<>?:}|+_)(*&^%$#@!~");
    char *sortedString[stringLength];
    while (string != NULL) {
        sortedString[x++] = string;
        string = strtok (NULL, " ,./;'`\"[]1234567890-=<>?:}|+_)(*&^%$#@!~");
        elementCount++;
    }
    qsort(sortedString, elementCount, sizeof (const char *), stringCompare);
    for (int x = 0; x < elementCount; ++x) {
        printf("%s\n", sortedString[x]);
    }
    return 0;
}

/*
TODO Paul
    Clean up code
        Add functions
        Improve complexity?
    Testcase file
    Readme
        Algorithm
        About qsort
        Design Decisions (Why 'A' comes before 'a')
*/
