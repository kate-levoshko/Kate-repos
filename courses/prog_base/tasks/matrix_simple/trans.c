#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fillRand(int mat[4][4]){
    int i,j;
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
                 mat[i][j]=rand() % 999 - 999;
        }
    }
}

void rotateCW180(int mat[4][4]){
    int i,j;
    int new_matrix;
    int n=4;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            new_matrix=mat[n-i+1][n+1-j];
        }
    }
}

void flipH(int mat[4][4]){
    int i,j, new_matrix, n=4;
    for (i=0;i<n;i++){
         for (j=0;j<n;j++){
             new_matrix=mat[i][n-j+1];
        }
     }
}

void transposSide(int mat[4][4]){
    int i,j, new_matrix, n=4;
    for (i=0;i<n;i++){
         for (j=0;j<n;j++){
             new_matrix=mat[n-j+1][n-i+1];
        }
     }
}
