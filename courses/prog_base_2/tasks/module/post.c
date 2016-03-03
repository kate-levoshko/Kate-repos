#include "post.h"

#define MAX_AMOUNT_OF_POSTS 100
#define MAX_AMOUNT_OF_SYMBOLS 200

struct arrayPost_s{
    post_t posts[MAX_AMOUNT_OF_POSTS];
    int postAmount;
};

struct post_s{
    char * data;
    int reposts;
};

arrayPost_t * arrayPost_create(){
    arrayPost_t p = (arrayPost_t)malloc(sizeof(struct arrayPost_s));
    p->postAmount = 0;
    return p;
}

void addPost(arrayPost_t self, int postPosition, char * data){
    int i;
    self->posts[self->postAmount] = (post_t)malloc(sizeof(struct post_s));
    self->posts[self->postAmount++]->data = (char*)malloc(MAX_AMOUNT_OF_SYMBOLS * sizeof(char));
    for (i = self->postAmount - 1; i >= postPosition + 1; i--){
        strcpy(self->posts[i]->data, self->posts[i - 1]->data);
        self->posts[i]->reposts = self->posts[i - 1]->reposts;
    }
    strcpy(self->posts[postPosition]->data,data);
}

void removePost(arrayPost_t self, int postPosition){
    int i;
    for(i = postPosition + 1;  i < self->postAmount; i++){
        strcpy(self->posts[i - 1]->data, self->posts[i]->data);
        self->posts[i - 1]->reposts = self->posts[i]->reposts;
    }
    free(self->posts[self->postAmount - 1]->data);
    free(self->posts[self->postAmount - 1]);
    self->postAmount--;
}

int getSizeOfPostList(arrayPost_t self, int postPosition){
    if(postPosition > Network_getNumOfPosts(self)){
        return -1;
    }
    return self->posts[postPosition]->reposts;
}

int getPostIndex(arrayPost_t self){ // function that return index of Post with max amount of reposts
    int max = randomRepostAmount(self,0);
    int index = 0;
    int i;
    for(i = 1; i < self->postAmount; i++){
        if(randomRepostAmount(self,i) > max){
            max = randomRepostAmount(self,i);
            index = i;
        }
    }
    return index;
}
void randomRepostAmount(arrayPost_t self){
    srand((unsigned)time(NULL));
    int i;
    for(i = 0; i < self->postAmount; i++){
        self->posts[i]->reposts = rand() % 100;
    }
}

int getPostAmount(arrayPost_t self){
    return self->postAmount;
}

char * getPostByIndex(arrayPost_t self, int postPosition){
    if(postPosition > getPostAmount(self)){
        return -1;
    }
    return self->posts[postPosition]->data ;
}

/*void Network_remove(arrayPost_t self){
    int i;
    for (i = 0; i< self->postAmount; i++){
        free(self->posts[i]->data);
    }
    for (i = 0; i< self->postAmount; i++){
        free(self->posts[i]);
    }
    free(self);
}*/
/*
void Network_addPost(arrayPost_t self, char * data){
    self->posts[self->postAmount] = (post_t)malloc(sizeof(struct post_s));
    self->posts[self->postAmount]->data = (char*)malloc(MAX_SIZE_OF_POST * sizeof(char));
    strcpy(self->posts[self->postAmount]->data,data);
    self->postAmount++;
}
*/

/*arrayPost_t Network_getArrayWithParameter(arrayPost_t self, int minNumOfReposts){
    arrayPost_t tmp = Network_create();
    int i;
    for(i = 0; i < self->postAmount; i++){
        if(Network_getNumOfReposts(self,i) > minNumOfReposts){
            Network_addPost(tmp, self->posts[i]->data);
            tmp->posts[tmp->postAmount - 1]->numOfReposts = Network_getNumOfReposts(self,i);
        }
    }
    return tmp;
}
*/