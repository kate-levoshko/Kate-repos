#include <string.h>

/*������ 21: � ������ ������� ��� ������ �����, ������� ����� �������.
  ������ ����� � ����� ���� ��� ����� ��������.
  � ��������� �������� ������ �����, ����� � ������� ��� ����� ����� �������� �� ������� �����.
*/


char * process(char * resultStr, const char * textLines[],
               int linesNum, const char * extraStr) {
                   int sum=0, i, j, P=1;
                   char *ptr=NULL;
                   const char *text;
                   int max=0, index=-1;


                        for (i=0; i<linesNum; i++){
                                text=textLines[i];
                                ptr=strtok(text, " ");
                                sum += atoi(ptr);
                                while (ptr!=NULL){
                                   ptr=strtok(NULL," ");
                                   sum += atoi(ptr);
                                }

                        }
                        if (sum>max)
                        {
                            max=sum;
                            index = i;
                        }
                        text = textLines[index];
                                ptr=strtok(text," ");
                                while (ptr!=NULL){
                                   P *= atoi(ptr);
                                   ptr=strtok(NULL," ");
                                }
                                sprintf(resultStr,"%i %i", index, P/strlen(text[index]));
                                return 0;
                   }
