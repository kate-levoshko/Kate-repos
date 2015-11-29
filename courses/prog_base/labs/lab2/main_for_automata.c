#include <stdio.h>
#include <stdlib.h>
void printArray(int arr1[], int size);
int main(){
    int size = 6;
    int arr1[6] = {0, 6, 7, 8, 9, 9};
	int arr2[6] = {-5, -5, -5, -5, -5, -5};
	int a = 6, b = 6;
	int c = run(arr1, a, arr2, b);
	printArray(arr1, size);
	for (a = 0; a < b; a++)
		printf(" %d ", arr2[a]);
	printf("\n %d ", c);
	return 0;
}

void printArray(int arr1[], int size){
      int i;
      printf("{");
        for (i = 0; i < size; i++){
            if (i==(size - 1)){
    printf("%3i ", arr1[i]);
    }
        else{
        printf("%3i,", arr1[i]);
        }
    }
    printf("}\n");
}
