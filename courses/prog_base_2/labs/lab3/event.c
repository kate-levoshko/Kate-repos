#include "event.h"

void event_subPrint(user_t * user){
	printf("INFORMATION FOR ADMIN:\n%s has been subscribed to Chat!\n\n", user_getUserName(user));
}
void event_unsubPrint(user_t * user){
	printf("INFORMATION FOR ADMIN:\n%s has been unsubscribed from Chat!\n", user_getUserName(user));
}
void event_notifNewMsgPrint(user_t * user, user_t* author){
	printf("%s has wtitten new message!\n", user_getUserName(author));
}



