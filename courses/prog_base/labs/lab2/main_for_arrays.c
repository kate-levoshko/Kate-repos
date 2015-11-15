#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRand2(int arr[], int size);
int checkRand2(int arr[], int size);
float meanValue(int arr[], int size);
int minValue(int arr[], int size);
int meanIndex(int arr[], int size);
int minIndex(int arr[], int size);
int maxOccurance(int arr[], int size);
int diff(int arr1[], int arr2[], int res[], int size);
void sub(int arr1[], int arr2[], int res[], int size);
int lt(int arr1[], int arr2[], int size);
void lxor(int arr1[], int arr2[], int res[], int size);
void printArray(int arr[], int size);
void printArray1(int arr1[], int size);
void printArray2(int arr2[], int size);

int main()
{
    int i, size = 5, res[5];
    int arr[size];
    int arr1[5] = {0, -1, 2, 3, 4};
    int arr2[5] =  {1, 2, 3, 4, 5};
    srand(time(NULL));
    fillRand2(arr, size);
    printArray(arr, size);
    printArray1(arr1, size);
    printArray2(arr2, size);
    printf("checkRand:%d\n", checkRand2(arr,size));
    printf("meanValue:%f\n",meanValue(arr, size));
    printf("minValue:%d\n", minValue(arr, size));
    printf("meanIndex:%d\n",meanIndex(arr, size));
    printf("minIndex:%d\n",minIndex(arr, size));
    printf("maxOccurance:%d\n",maxOccurance(arr, size));
    printf("diff:%d\n",diff(arr1, arr2, res, size));
    printf("lt:%d\n",lt(arr1, arr2, size));
}
void printArray(int arr[], int size){
      int i;
      printf("{");
        for (i = 0; i < size; i++){
            if (i==(size - 1)){
    printf("%5i ", arr[i]);
    }
        else{
        printf("%5i, ", arr[i]);
        }
    }
    printf("}\n");
}

  void printArray1(int arr1[], int size){
      int i;
      printf("{");
        for (i = 0; i < size; i++){
            if (i==(size - 1)){
    printf("%5i ", arr1[i]);
    }
        else{
        printf("%5i, ", arr1[i]);
        }
    }
    printf("}\n");
}
void printArray2(int arr2[], int size){
      int i;
      printf("{");
        for (i = 0; i < size; i++){
            if (i==(size - 1)){
    printf("%5i ", arr2[i]);
    }
        else{
        printf("%5i, ", arr2[i]);
        }
    }
    printf("}\n");
}
