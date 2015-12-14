#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int satisfies(int, int, int);

int main() {
    int aval = 0, bval = 0, cval = 0;
    int resultVal;

    resultVal = satisfies(aval, bval, cval);

    printf("%i", resultVal);
    return 0;
}
int is2(int modmin){
    return log(modmin)/log(2)-(int)(log(modmin)/log(2))==0;
}
// copy the code below to the answers files and add #include <math.h> at the beginning
int satisfies(int a, int b, int c) {
   int result;
   int min1,max1,min2, modmin, sum2;

   if (a<0 && b<0 && c<0){
       if (a<b && b<c){ {
          min1 = a;
          sum2 = (b+c);
          }
          if (b<a&&a<c) {
            min1 = b;
            sum2 = (a+c);
          }
          else{
            min1 = c;
            sum2 = (a+b);
          }
       }
       modmin = abs(min1);

   if (sum2<-256 && modmin<256 && is2(modmin)==1)
      return 1;
      else {
        if (abs(sum2)>16 || modmin>8)
            return 1;
      if (a<0&&a>-256 || b<0&&b>-256 || c<0&&c>-256)
          return 1;
          else
            return 0;
      }

    if ((a<0 && b<0 && (a+b)*3>-256) || (b<0 && c<0 && (b+c)*3>-256) || (a<0 && c<0 && (a+c)*3>-256))
        return 1;
         else
          return 0;
   }
    if (a>=0 && b>=0 && c>=0){
            max1=max(max(a,b),c);
<<<<<<< HEAD
            min2=min(min(a,b),c)
=======
            min2=min(min(a,b),c);
>>>>>>> results
                if ((max1)-(min2)>32)
        return 1;
    else
        return 0;
    }
  return result;
}
