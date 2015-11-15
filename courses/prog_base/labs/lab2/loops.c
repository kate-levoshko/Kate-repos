#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calc(int n, int m);

int main() {
    int nval = 2, mval = 9;
    double result;

    result = calc(nval, mval);

    printf("%f", result);
    return 0;
}

double calc(int n, int m){
    double result, sum;
    int i, j;
    int n1=2, n0=1;

    for (i=1; i<=n; i++){
            sum=0;
        for (j=1; j<=m; j++){
                sum += (n1+(1/(float)(j+n1)));
            }
            result += i*sum;
    }
    return result;
}

