#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double long2double(long long number) {

int exponent=0, i = 0;
int sign,j;
int binary[64];
double mantissa=0,result;
long long num_bin;

if (number < 0) sign = 1;
else sign = 0;

for (i = 63; i >= 0; i--)
{
num_bin = number;
num_bin = num_bin >> 1;
num_bin = num_bin << 1;
if (number == num_bin)
binary[i] = 0;
else
binary[i] = 1;
number = number >> 1;
}
for (i = 11,j=0; i >= 1; i--,j++)
{
exponent = exponent + binary[i] * pow(2, j);
}
for (i = 12, j = -1; i <= 63; i++, j--)
{
mantissa = mantissa + binary[i] * pow(2, j);
}
if (0 < exponent < 2047)
result = pow(-1, sign)*(1 + mantissa)*pow(2, exponent - 1023);//Normalized form
else if (exponent = 0 && mantissa != 0)
result = pow(-1, sign)*mantissa*pow(2, -1022);//Denormalized form
else if ((exponent = 0) && (mantissa = 0)){
if (sign == 1)
result = -0;
else
result = 0;
}
else if (exponent= 2047){
if ((mantissa == 0) && (sign = 1))
result = -INFINITY;
else
result = +INFINITY;
}
else if ((exponent = 2047) && (mantissa != 0))
result = NAN;

else result = sign*pow(2,exponent-1023) *(1+mantissa);
return result;
}
int main(){
printf("%.325llf", long2double(4620000000000000000LL));
}
