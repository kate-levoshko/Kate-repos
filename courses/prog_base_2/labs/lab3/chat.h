#include "user.h"

#define MAX_AMOUNT_OF_USERS 10

typedef struct chat_s chat_t;
enum ChatError {
	CHAT_OK,
	CHAT_OVERFLOW,
	CHAT_EMPTY
};
chat_t * chat_new();
void chat_free(chat_t * self); 

int chat_getNumOfUsers(chat_t * self);
void chat_connectUser(chat_t * self, user_t * user);
void chat_connectAdmin(chat_t * self, admin_t * admin);
void chat_unconnectUser(chat_t * self); 
enum ChatError chat_getStatus(chat_t * self);

void chat_work(chat_t * self);

