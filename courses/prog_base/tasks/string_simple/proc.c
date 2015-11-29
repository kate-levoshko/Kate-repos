#include <string.h>

/*Âàð³àíò 21: Ó ðÿäêàõ çàïèñàí³ ö³ë³ äîäàòí³ ÷èñëà, ðîçä³ëåí³ îäíèì ïðîá³ëîì.
  Çíàéòè ðÿäîê ó ÿêîìó ñóìà öèõ ÷èñåë íàéá³ëüøà.
  Ó ðåçóëüòàò çàïèñàòè ³íäåêñ ðÿäêà, ïðîá³ë ³ äîáóòîê öèõ ÷èñåë ðÿäêà ïîä³ëåíèé íà äîâæèíó ðÿäêà.
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
