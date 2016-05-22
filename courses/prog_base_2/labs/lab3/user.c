#include "user.h"

struct user_s{
	char name[200];
	chat_newMessage_cb msgCallback;
};

struct admin_s{
	char name[200];
	chat_subscribe_cb subCallback;
	chat_unsubscribe_cb unsubCallback;
	chat_newMessage_cb msgCallback;
};

user_t * user_new(char * name){
	user_t * us = malloc(sizeof(struct user_s));
	strcpy(us->name, name);
	return us;
}

void user_free(user_t * self){
	free(self);
}

admin_t * user_newAdmin(char * name){
	admin_t * adm = malloc(sizeof(struct admin_s));
	strcpy(adm->name, name);
	return adm;
}

void user_deleteAdmin(admin_t * admin){
	free(admin);
}

void user_setUserEvents(user_t * self, chat_newMessage_cb msgCallback){
	self->msgCallback = msgCallback;
}

void user_setAdminEvents(admin_t * admin, chat_subscribe_cb subCallback, chat_unsubscribe_cb unsubCallback, chat_newMessage_cb msgCallback){
	admin->subCallback = subCallback;
	admin->unsubCallback = unsubCallback;
	admin->msgCallback;
}

char * user_getUserName(user_t * user){
	return user->name;
}

chat_subscribe_cb user_getSubCallback(admin_t * admin){
	return admin->subCallback;
}

chat_unsubscribe_cb user_getUnsubCallback(admin_t * admin){
	return admin->unsubCallback;
}

chat_newMessage_cb user_getNewMsgCallback(admin_t * admin, user_t * user){
	return user->msgCallback;
}

