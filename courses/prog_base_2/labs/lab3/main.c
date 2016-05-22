#include "chat.h"
#include "user.h"
#include "event.h"

int main(void){
	runTests();
	/*
	chat_t * chat = chat_new();

	admin_t * admin = user_newAdmin("ADMIN");
	user_setAdminEvents(admin, event_subPrint, event_unsubPrint, event_notifNewMsgPrint);

	user_t * user1 = user_new("Katya");
	user_setUserEvents(user1, event_notifNewMsgPrint);

	user_t * user2 = user_new("Ruslan");
	user_setUserEvents(user2, event_notifNewMsgPrint);

	chat_connectAdmin(chat, admin);
	chat_connectUser(chat, user1);
	chat_connectUser(chat, user2);

	chat_work(chat);
	
	chat_free(chat);
	*/
	getchar();
	return 0;
}