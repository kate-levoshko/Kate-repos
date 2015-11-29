#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>

struct Cube {
    int x, y, z;
    int cube[x][y][z];
};

void fillRand(int size, struct Cube p[size]) {
    int i, j, k;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            for(k = 0; k < size; k++) {
                p[i].x = rand() % 10 - 5;
                p[j].y = rand() % 10 - 5;
                p[k].z = rand() % 10 - 5;
            }
        }
    }
}
double isCross (int size, struct Cube p[size]){
    int i, j, k;
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            for(k = 0; k < size; k++) {
                if(p[i].x = p[j].y || p[j].y = p[k].z){
                        printf("%i %i %i", i, j, k);
                }
            }
        }
    }
}

int main(void) {
    int number = 3;
    struct Point3D pList[number];
    srand(time(NULL));
    fillRand(number, pList);

    struct Cube;
    return 0;
    /* I am sorry, I am very stupid :( */
}
