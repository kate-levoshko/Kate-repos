#include <stdio.h>
#include <stdlib.h>

struct TRACK {
    char * tracks;
    float length;
};

struct GROUP {
    struct TRACK * tracks;
    int amount; // the amount of participants
};

void ptrst1(struct TRACK * st1){
    printf(" %s %i\n", (*st1).tracks, (*st1).length);
}

void ptrst2 (struct GROUP * st2){
    printf(" %s %i\n", (*st2).tracks, (*st2).amount);
}

int main()
{
    int i;
        struct TRACK st1[10]={{"My love", 6.02},
                            {"Cool", 2.43},
                            {"Never give up", 5.04},
                            {"Be careful", 4.45},
                            {"It`s my life", 4.43},
                            {"First sight", 2.34},
                            {"Childhood", 6.43},
                            {"Friends", 4.23},
                            {"Mother", 6.34},
                            {"Big city life", 6.23}};

        struct GROUP st2[10]={{"My love", 4},
                            {"Cool", 2},
                            {"Never give up", 3},
                            {"Be careful", 3},
                            {"It`s my life", 1},
                            {"First sight", 4},
                            {"Childhood", 6},
                            {"Friends", 7},
                            {"Mother", 2},
                            {"Big city life", 3}};
        size_t size = sizeof(st1)/sizeof(struct TRACK);
        ptrst1(st1);
        ptrst2(st2);
    //struct TRACK * tr = &tracks[i-1];
}
