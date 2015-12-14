#include <stdio.h>
#include <stdlib.h>

struct Photos {
    char * album;
    int year;
    int num;
};

void printst(int size, struct Photos albums[size]){
    int i;
    for (i = 0; i < size; i++){
        printf("%i) Album: %s\n year: %i\n Amount of photos: %i\n", (i+1), albums[i].album, albums[i].year, albums[i].num);
    }
    puts("");
}

int count(int size, struct Photos albums[size]){
    int i, amount = 0;
    for (i = 0; i < size; i++){
        if (albums[i].num > 10){
            amount++;
        }
    }
    return amount;
}

void change(struct Photos * pVar, const char * newValue){
    (*pVar).album = newValue;
}

void print(struct Photos* pVar){
   printf(" %s\n year %i Amount of photos %i\n", (*pVar).album, (*pVar).year, (*pVar).num);
}

int main()
{
    char ch[100];
    struct Photos albums[10]={{"My Work", 2014, 11},
                              {"School", 2009, 8},
                              {"Birthday_17", 2015, 20},
                              {"Concert", 2010, 15},
                              {"Easter", 2014, 6},
                              {"School leaver party", 2015, 250},
                              {"Holidays", 2013, 50},
                              {"Friends", 2011, 9},
                              {"Documents", 2014, 3},
                              {"KPI_LOVE", 2015, 7}};
    const char* newalbum;
    int i, amount;
    size_t size = sizeof(albums)/sizeof(struct Photos);
    printst(size, albums);
    printf("Enter the number of album [1 ... %i], you want to change ", size);
    scanf("%i", &i);
    fflush(stdin);
    if (i < 1 || i > 10){
        puts("ERROR! There is not such album as you choose");
    }
    else{
        printf("Enter the name of new album\n");
          newalbum = gets(ch);
          puts("");
          struct Photos * p = &albums[i-1];
          change(p, newalbum);
          amount = count(size, albums);
          printf("amount = %i\n\n", amount);
          print(p);
    }
    return 0;
}
