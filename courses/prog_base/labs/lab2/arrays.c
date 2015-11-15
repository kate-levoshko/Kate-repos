#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillRand2(int arr[], int size){
int i;
     for (i=0; i<size; i++){
        arr[i] = rand() % 511-255;
     }
}

int checkRand2(int arr[], int size){
    int i;
    for (i=0; i<size; i++){
            if (arr[i]<=-255 || arr[i]>=255){
                return 0;
             }
    }
    return 1;
}
float meanValue(int arr[], int size){
    int i, sum=0;
    for (i=0; i<size; i++){
        sum += arr[i];
    }
    return sum/(float)size;
}
int minValue(int arr[], int size){
    int i, min = arr[0];
    for (i=0; i<size; i++){
        if (arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int meanIndex(int arr[], int size){
    int i, index = 0;
    float mean = meanValue(arr, size);
    float p = fabs(arr[0]-mean);
    for (i=1; i<size; i++){
       if (fabs(arr[i]-mean)<p){
            index=i;
       }
    }
    return index;
}
int minIndex(int arr[], int size){
    int i, index = 0;
    int min = minValue(arr, size);
       for (i=0; i<size; i++){
            if (min==arr[i]){
                index = i;
            }
        }
    return index;
}

int maxOccurance(int arr[], int size)
{
	int i ,j;
	int a = 1, b = 1;
	int max = arr[0];
	for (i = 0; i < size; i++){
		for (j = i + 1; j < size; j++)
			if (arr[j] == arr[i])
				b++;
		if (b >= a){
			a = b;
			max = arr[i];
		}
		if(b == a && arr[i] > max)
			max = arr[i];

		b = 1;
	}
	return max;
}

int diff(int arr1[], int arr2[], int res[], int size){
    int i;
    for (i=0; i<size; i++){
        res[i] = arr1[i] - arr2[i];
        if (res[i] != 0){
            return 0;
        }
    }
    return 1;
}

void sub(int arr1[], int arr2[], int res[], int size){
    int i;
    for (i=0; i<size; i++){
        res[i] = arr1[i] - arr2[i];
    }
}

int lt(int arr1[], int arr2[], int size){
    int i;
	for (i = 0; i < size; i++){
		if (arr1[i] >= arr2[i]){
			return 0;
		}
	}
    return 1;
}

void lxor(int arr1[], int arr2[], int res[], int size){
    	int i;
	for (i = 0; i < size; i++){
        res[i]=arr1[i] ^ arr2[i];
        }
}

