#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct post_s * post_t;
typedef struct arrayPost_s * arrayPost_t;

arrayPost_t arrayPost_create();


void post_addPost(arrayPost_t self, int postPosition, char * data);
void post_removePost(arrayPost_t self, int postPosition);
int post_getSizeOfPostList(arrayPost_t self, int postPosition);
int post_getPostIndex(arrayPost_t self);
void post_randomRepostAmount(arrayPost_t self);
int post_getPostAmount(arrayPost_t self){
char * post_getPostByIndex(arrayPost_t self, int postPosition);

#endif // NETWORK_H_INCLUDED
