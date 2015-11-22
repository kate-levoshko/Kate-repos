#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(double, double, double);

int main() {
    double xval = -7, yval = 1, zval = 9;
    double result;

    result = calc(xval, yval, zval);

    printf("%.12f", result);
    return 0;
}

// copy the code below to the answers files and add #include <math.h> at the beginning

double calc(double x, double y, double z) {
   double a,a0,a1,a2;
   if ((z==0)||(x-y==0)||(x+y==0)){
     return nan("");
   }
   else{
   a0=pow(x,x+1)/pow(x-y,1/z); // бесконечность
   a1=y/(2*abs(x+y));
   a2=pow(2+sin(y),cos(x)/z+abs(x-y));
   a=a0+a1+a2;
   }
   return a;
}
