#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1={"a, b, c"};
    char str2={"  a,  b,   c"};
    char delim=(" ");
    char a=strtok(str1, delim);
    char b=strtok(str2, delim);

    if (strlen(str1)!=strlen(str2)){
            puts("ERROR");
    }
       else{
           if (strlen(a)=strlen(b)){
              puts("strings are equal");
                else
              puts("strings are NOT equal");
           }
        }
    }
