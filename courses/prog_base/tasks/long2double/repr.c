#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double long2double(long long number) {
double mantissa=0,exponenta=0, result;
short sign,i,j;

sign=(number>>63)&1;
for (j=52;j<63;++j) {
        exponenta+=((number>>j)&1)*(pow(2,(j-52)));
}

for (i=51;i>=0;--i) {
	mantissa+=(((number>>i)&1)*(pow(2,i-52)));
}
if ((exponenta==2047) && mantissa!=0) {
return NAN;
}
if ((exponenta==2047) && (mantissa==0) && (sign==1)) {
	return -INFINITY;
	}
if ((exponenta==2047) && (mantissa==0) && (sign==0)) {
	return INFINITY;
	}
if ((exponenta>0) && (exponenta<2047)){
result=pow(-1,sign)*pow(2,exponenta-1023)*(1+mantissa);
return result;
}
if ((exponenta==0) && (mantissa!=0)) {
	result=pow(-1,sign)*pow(2,-1022)*mantissa;
	return result;
}
if ((exponenta==0) && (mantissa==0) && (sign==1)){
	return -0;
}
if ((exponenta==0) && (mantissa==0) && (sign==0)){
	return 0;
}
}
int main(){
printf("%.325llf",long2double(0));
}
