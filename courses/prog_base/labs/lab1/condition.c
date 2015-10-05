#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int satisfies(int, int, int);

int main() {
    int aval = -32, bval = -200, cval = -57;
    int resultVal;

    resultVal = satisfies(aval, bval, cval);

    printf("%i", resultVal);
    return 0;
}
int is2(int modmin){
    if (log(modmin)/log(2)-(int)(log(modmin)/log(2))==0)
        return 1;
    else
        return 0;
}
// copy the code below to the answers files and add #include <math.h> at the beginning
int satisfies(int a, int b, int c) {
   int result;
   int min,max,min2, modmin, sum2;

   if ((a<0)&&(b<0)&&(c<0)){
       if ((a<b)&&(b<c)){ {
          min = a;
          sum2 = (b+c);
          }
          if ((b<a)&&(a<c)) {
            min = b;
            sum2 = (a+c);
          }
          else{
            min = c;
            sum2 = (a+b);
          }
       }
       modmin = abs(min);

   if ((sum2<-256)&&(modmin<256)&&(is2(modmin)==1))
      return 1;
      else {
        if (abs(sum2)>16||modmin>8)
            return 1;
      if ((a<0&&a>-256)||(b<0&&b>-256)||(c<0&&c>-256))
          return 1;
          else
            return 0;
      }
   }

    if ((a<0&&b<0&&(a+b)*3>-256)||(b<0&&c<0&&(b+c)*3>-256)||(a<0&&c<0&&(a+c)*3>-256))
        return 1;
         else
          return 0;
    if (a>0&&b>0&&c>0){
        if (a>b&&a>c){
            a = max;
            if (b>c&&b>a)
                b = max;
                else c = max;
                }
        if (a<b&&a<c)
            a=min2;
        if (b<c&&b<a)
            b=min2;
        else
            c=min2;
    }
    if (max-min2>32)
        return 1;
    else
        return 0;
    return result;
}
