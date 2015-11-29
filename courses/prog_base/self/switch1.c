#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int code;
    float sum, h,m;
    scanf("%i",&code);
    scanf("%f %f",&h, &m);
    if (code<10||code>999){
        puts("ERROR");
        }
     else{

    switch(code){
    case 44:
        sum=0.77*(60*h+m);
        break;
    case 62:
        sum=0.8*(60*h+m);
        break;
    case 32:
        sum=0.95*(60*h+m);
        break;
    case 692:
        sum=1.5*(60*h+m);
        break;
    case 697:
        sum=1.5*(60*h+m);
        break;
    default:
        sum=(60*h+m);
        break;
    }
    }
  printf("%f",sum);
    return 0;
}
