#include "queue.h"

struct queue_s{
	int arr[MAX_ELEMENTS_OF_ARRAY];
	int qSize;
	int head;
	int tail;
};

queue_t * queue_createQueue(void){
	queue_t * q = malloc(sizeof(struct queue_s));
	q->head = 0;
	q->tail = 0;
	q->qSize = 0;
	q->arr[0] = '\0';
	return q;
};

void queue_free(queue_t * self){
	free(self);
}

void queue_enqueue(queue_t * self, int element){
	if (self->qSize == MAX_ELEMENTS_OF_ARRAY){
		printf("We can`t add new element");
		exit(EXIT_SUCCESS);
	}
	self->arr[self->tail] = element;
	self->qSize++;
	self->tail++;
}

int queue_dequeue(queue_t * self) {
    if (self->tail > 0) {
    int element = self->arr[self->head];
    for(int i = 1; i < self->qSize; i++){
    self->arr[i-1] = self->arr[i];
    }
    self->tail--;
    self->qSize--;
    return element;
    }
}
int queue_head(queue_t * self){
	return self->head;
}

int queue_getCount(queue_t * self){
    return self->qSize;
}
int queue_getSum(queue_t * self){
    int sum = 0;
    for(int i = 0; i <  queue_getCount(self); i++){
        sum += self->arr[i];
    }
    return sum;
}

void queue_print(queue_t * self){
	for (int i = 0; i < self->qSize; i++){
		printf("%d ", self->arr[i]);
	}
}
