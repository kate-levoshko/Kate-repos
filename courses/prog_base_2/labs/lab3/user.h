#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

typedef struct user_s user_t;
typedef struct admin_s admin_t;

typedef void(*chat_subscribe_cb)(user_t * user);		// user
typedef void(*chat_unsubscribe_cb)(user_t * user);		// user
typedef void(*chat_newMessage_cb)(user_t * user, user_t * author);		//user, admin


user_t * user_new(char * name);
void user_free(user_t * self);

admin_t * user_newAdmin(char * name);
void user_deleteAdmin(admin_t * admin);

void user_setUserEvents(user_t * self, chat_newMessage_cb msgCallback);
void user_setAdminEvents(admin_t * admin, chat_subscribe_cb subCallback, chat_unsubscribe_cb unsubCallback, chat_newMessage_cb msgCallback);

char * user_getUserName(user_t * user);
chat_subscribe_cb user_getSubCallback(admin_t * admin);
chat_unsubscribe_cb user_getUnsubCallback(admin_t * admin);
chat_newMessage_cb user_getNewMsgCallback(admin_t * admin, user_t * user);

