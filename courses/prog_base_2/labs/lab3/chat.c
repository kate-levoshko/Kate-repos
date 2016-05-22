#include "chat.h"

struct chat_s{
	user_t * users[MAX_AMOUNT_OF_USERS];
	admin_t  * admin;
	int numOfUsers;
	enum ChatError status;
};

chat_t * chat_new(void){
	chat_t * ch = malloc(sizeof(struct chat_s));
	ch->numOfUsers = 0;
	return ch;
}

void chat_free(chat_t * self){
	for (int i = 0; i < self->numOfUsers; i++){
		user_free(self->users[i]);
	}
	free(self);
}

void chat_connectUser(chat_t * self, user_t * user){
	if (self->numOfUsers >= MAX_AMOUNT_OF_USERS){
		self->status = CHAT_OVERFLOW;
		exit(EXIT_SUCCESS);
	}
	self->users[self->numOfUsers++] = user;
	self->status = CHAT_OK;
}

void chat_unconnectUser(chat_t * self){
	if (self->numOfUsers <= 0){
		self->status = CHAT_EMPTY;
		exit(EXIT_SUCCESS);
	}
	self->users[self->numOfUsers--] = NULL;
	self->status = CHAT_OK;
}

void chat_connectAdmin(chat_t * self, admin_t * admin){
	self->admin = admin;
	self->status = CHAT_OK;
}

int chat_getNumOfUsers(chat_t * self){
	return self->numOfUsers;
}

enum ChatError chat_getStatus(chat_t * self){
	return self->status;
}

void chat_work(chat_t * self){
	for (int i = 0; i < self->numOfUsers; i++){
		user_getSubCallback(self->admin)(self->users[i]);
	}
	
	/*for (int i = 0; i < self->numOfUsers; i++){
		user_getUnsubCallback(self->admin)(self->users[i]);
	}
	return;
	*/
		while (1){
			int authorNum = rand() % self->numOfUsers;
			for (int i = 0; i < self->numOfUsers; i++){
				if (i != authorNum){
					user_getNewMsgCallback(self->admin, self->users[i])(self->users[i], self->users[authorNum]);
				}
			}
			Sleep(1000);
	}
}
