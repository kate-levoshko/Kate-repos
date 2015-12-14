#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int exec(int, int, int);


int main() {
    int opval = 4, aval = 10, bval = 5;
    int resultVal;

    resultVal = exec(opval, aval, bval);

    printf("%i", resultVal);
    return 0;
}
// copy the code below to the answers files and add #include <math.h> at the beginning
int exec(int op, int a, int b) {
   int result, HELP, size_of_data;

   if (op<0){
       HELP=a;
       a=b;
       b=HELP;
       op=(-op);
   }

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
       result=(pow(a,b));
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
          switch(abs(b) % 8) {
      case 0:
        size_of_data=(sizeof(char));
        break;
      case 1:
        size_of_data=(sizeof(signed char));
        break;
      case 2:
        size_of_data=(sizeof(short));
        break;
      case 3:
        size_of_data=(sizeof(unsigned int));
        break;
      case 4:
        size_of_data=(sizeof(long));
        break;
      case 5:
        size_of_data=(sizeof(unsigned long long));
        break;
      case 6:
        size_of_data=(sizeof(float));
        break;
      case 7:
        size_of_data=(sizeof(double));
        break;
    }
    result=(abs(a)*size_of_data);

        break;
    case 11:
        if (a==0){
            result=0;
        }
            else
        result=(2*M_PI*cos((3*a*b)/a));
        break;
        default:
    if (op < 100) {
        result=(op % abs(a + 1)) + (op % abs(b + 1));
    }
          else
            if (op>=100)
            result=(-1);
            break;
       }
    return result;
}
