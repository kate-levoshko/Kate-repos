#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	int * i = (int*)malloc(sizeof(int));
	int * number = (int*)malloc(sizeof(int));
	char * string = (char*)malloc(20* sizeof(char));
    puts("Please, enter your string");
	gets(string);
	* number = 0;
	for (*(i) = 0; *(i) < strlen(string); *(i)++){
		if (isalpha(string[*i])){
			*(number)+=1;
		}
	}
	printf("%i", *number);
    free(i);
	free(number);
	free(string);
}
