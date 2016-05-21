#include <stdio.h>
#include <stdlib.h>

#pragma once

#define MAX_ELEMENTS_OF_ARRAY 1000

typedef struct queue_s queue_t;

queue_t * queue_createQueue(void);
void queue_free(queue_t * self);

void queue_enqueue(queue_t * self, int element);
int queue_dequeue(queue_t * self);
int queue_head(queue_t * self);
int queue_getCount(queue_t * self);
int queue_getSum(queue_t * self);
void queue_print(queue_t * self);
