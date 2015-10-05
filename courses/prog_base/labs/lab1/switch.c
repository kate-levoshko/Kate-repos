#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int exec(int, int, int);
int min (int a, int b){

}
int max (int a, int b){

}
int power (int a, int b){

}
int sizeOfNum (int a, int b){

}
int main() {
    int opval = 3, aval = 1, bval = 2;
    int resultVal;

    resultVal = exec(opval, aval, bval);

    printf("%i", resultVal);
    return 0;
}
// copy the code below to the answers files and add #include <math.h> at the beginning
int exec(int op, int a, int b) {
   int result, HELP;
   double (PI)=(3,141592653589793238462643);

   if (op<0){
       HELP=a;
       a=b;
       b=HELP;
   }
    else{

   switch(op){
   case 0:
       result=(-a);
       break;
   case 1:
       result=(a+b);
       break;
   case 2:
       result=(a-b);
       break;
   case 3:
       result=(a*b);
       break;
   case 4:
       result=(a/b);
       break;
   case 5:
       result=(abs(a));
       break;
   case 6:
       result=(power(a,b));
       break;
   case 7:
   case 13:
   case 77:
       result=(a%b);
       break;
    case 8:
       result=(max(a,b));
       break;
    case 9:
       result=(min(a,b));
       break;
    case 10:
        result=(sizeOfNum(a, b));
        break;
    case 11:
        result=(2*PI*cos((3*a*b)/a));
        break;
    if (op < 100) {
       default:
        result=(op % abs(a + 1)) + (op % abs(b + 1));
    }
          else
            result=(-1);
            break;
       }
    }

    return result;
}
