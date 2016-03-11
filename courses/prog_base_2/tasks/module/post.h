#ifndef POST_H_INCLUDED
#define POST_H_INCLUDED

#define MAX_AMOUNT_OF_POSTS 100
#define MAX_AMOUNT_OF_SYMBOLS 400

typedef struct list_s list_t;

enum ListError {
	LIST_OK,
	LIST_OVERFLOW,
	LIST_EMPTY,
	WRONG_INDEX,
	INCORRECT_AMOUNT
};

list_t * list_new(void);  // constructor

void list_free(list_t * self);  // destructor

void list_setPostAt(list_t * self, int index, char * text); // function, that add post
void list_postRemove(list_t * self, int index); // function, that delete post
int list_getSize(list_t * self); // function, that get the amount of posts
int list_getIndex(list_t * self); // function, that get index of post with max amount of reposts
list_t * listOfPosts(list_t * self, int numOfRepost); // list of posts, where the amount of reposts > than value  

#endif // POST_H_INCLUDED
