#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

  void fprocess(const char * pread, const char * pwrite){
    int i, number = 0;
	char string[500];
	FILE * fpstr = fopen("string.txt", "r");
	FILE * fpresult = fopen("result.txt", "w");
	if (NULL == fpstr){
        puts("ERROR");
        exit(EXIT_SUCCESS);
	}
        fgets(string, 500, fpstr);

		for (i = 0; i < strlen(string); i++){
            if (toupper(string[i]) == 'A'){
                number++;
                fputs(fpresult, number);
            }
            else if (toupper(string[i]) == 'E'){
                number++;
                fputs(fpresult, number);
            }
            else if (toupper(string[i]) == 'Y'){
                number++;
                fputs(fpresult, number);
            }
            else if (toupper(string[i]) == 'U'){
                number++;
                fputs(fpresult, number);
            }
            else if (toupper(string[i]) == 'O'){
                number++;
                fputs(fpresult, number);
            }
            else if (toupper(string[i]) == 'I'){
                number++;
                fputs(fpresult, number);
            }

        }

		fclose(fpresult);
		fclose(fpstr);
}

int main()
{
    fprocess("string.txt", "result.txt" );
}
