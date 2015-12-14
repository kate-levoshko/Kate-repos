#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fprocess(const char * pread, const char * pwrite){
    int i;
    int point1, point2;
    char command1[100];
    char command2[100];
    char string[500];
    FILE * fpdata = fopen(pread, "r");
    FILE * fpresult = fopen(pwrite, "w");

    if (NULL == fpdata){
    fputs("ERROR", fpresult);
    }

    for (i = 1; i <= 21; i++){
        fgets(string, 500, fpdata);
    }
    sscanf(string, "%s %d %s %d", command1, &point1, command2, &point2);
    if (point1 > point2){
        fputs(command1, fpresult);
    }
    else if (point1 == point2){
        fputs("DRAW", fpresult);
    }
    else fputs(command2, fpresult);
    fclose(fpresult);
    fclose(fpdata);
}
