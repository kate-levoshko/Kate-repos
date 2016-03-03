#ifndef NETWORK_H_INCLUDED
#define NETWORK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct post_s * post_t;
typedef struct arrayPost_s * arrayPost_t;

arrayPost_t arrayPost_create();


void addPost(arrayPost_t self, int postPosition, char * data);
void removePost(arrayPost_t self, int postPosition);
int getSizeOfPostList(arrayPost_t self, int postPosition);
int getPostIndex(arrayPost_t self);
void randomRepostAmount(arrayPost_t self);
int getPostAmount(arrayPost_t self){
char * getPostByIndex(arrayPost_t self, int postPosition);

#endif // NETWORK_H_INCLUDED
