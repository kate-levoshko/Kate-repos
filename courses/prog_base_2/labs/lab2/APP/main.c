#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#include "queue.h"

typedef int (*cmp_f)(queue_t * self);
typedef int (*react_f)(queue_t * self);

typedef struct dynamic_s {
    HANDLE hLib;
    cmp_f cmp;
    react_f react;
} dynamic_t;
const int MAX_QUEUE_SIZE = 100;
dynamic_t * dynamic_init(const char * dllName);
void dynamic_clean(dynamic_t * dyn);
const char * userChoice();
void printQueue(queue_t * self, int sum);


int main(){
    queue_t * q1 = queue_createQueue();
    const char * dllName = userChoice();
    dynamic_t * dll = dynamic_init(dllName);
    int sum = 0;
    if (NULL == dll) {
        printf("Can't load dynamic!\n");
        return 1;
    }
    if (NULL == dll->cmp) {
        printf("Can't get compare function!\n");
        return 1;
    }
    if (NULL == dll->react) {
        printf("Can't get reaction function!\n");
        return 1;
    }
    srand(time(NULL));
    printf("Dynamic loaded!\n");
    while (queue_getCount(q1) < MAX_QUEUE_SIZE){
        queue_enqueue(q1, rand() % 100);
        printQueue(q1, sum);
        if(dll->cmp(q1)) {
            sum = dll->react(q1);
        }
    }
    queue_free(q1);

    return 0;
}

const char * userChoice() {
    int dllNum = 0;
    while (dllNum < 1 || dllNum > 2) {
        printf("Choose DLL to load:\n1. DLL1\n2. DLL2\n> ");
        scanf("%i", &dllNum);
        if (dllNum == 1) {
            return "DLL1.dll";
        } else if (dllNum == 2) {
            return "DLL2.dll";
        }
    }
    return NULL;
}

dynamic_t * dynamic_init(const char * dllName) {
    dynamic_t * dyn = malloc(sizeof(struct dynamic_s));
    dyn->hLib = LoadLibrary(dllName);
    dyn->cmp = NULL;
    dyn->react = NULL;
    if (NULL != dyn->hLib) {
        dyn->cmp = (cmp_f)GetProcAddress(dyn->hLib, "compare");
        dyn->react = (react_f)GetProcAddress(dyn->hLib, "reaction");
        return dyn;
    } else {
        return NULL;
    }
}

void printQueue(queue_t * self, int sum) {
    system("cls");
    printf("Queue: \n");
    queue_print(self);
    printf("\nSum : %d", sum);
    Sleep(500);

}

void dynamic_clean(dynamic_t * dyn) {
    FreeLibrary(dyn->hLib);
    free(dyn);
}
