#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n;
    int arr[n], newArr[n];
    scanf("%i", &n);
    for (i=0;i<n;i++){
        scanf("%i", &arr[i]);
    }
    for (i=0; i<n; i++){
        newArr[i]=arr[i+2];
        printf("%i", newArr[i]);

    }
 return 0;
}