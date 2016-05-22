#include <stdlib.h>  
#include <stdarg.h>  
#include <stddef.h>  
#include <setjmp.h>  

#include "user.h"
#include "chat.h"

#include <cmocka.h>

static void numOfUsers_emptyChat_zeroCount(void ** state){
	chat_t * chat = chat_new();
	assert_int_equal(chat_getNumOfUsers(chat), 0);
	chat_free(chat);
}

static void connectUsers_numOfConnectedUsers_oneCount(void ** state){
	chat_t * chat = chat_new();
	user_t * user1 = user_new("Katya");
	chat_connectUser(chat, user1);
	assert_int_equal(chat_getNumOfUsers(chat), 1);
	chat_free(chat);
}

static void connectUsers_overflowOfUsers_status(void ** state){
	chat_t * chat = chat_new();
	user_t * user1 = user_new("A");
	user_t * user2 = user_new("A");
	user_t * user3 = user_new("A");
	user_t * user4 = user_new("A");
	user_t * user5 = user_new("A");
	user_t * user6 = user_new("A");
	user_t * user7 = user_new("A");
	user_t * user8 = user_new("A");
	user_t * user9 = user_new("A");
	user_t * user10 = user_new("A");
	user_t * user11 = user_new("A");
	chat_connectUser(chat, user1);
	chat_connectUser(chat, user2);
	chat_connectUser(chat, user3);
	chat_connectUser(chat, user4);
	chat_connectUser(chat, user5);
	chat_connectUser(chat, user6);
	chat_connectUser(chat, user7);
	chat_connectUser(chat, user8);
	chat_connectUser(chat, user9);
	chat_connectUser(chat, user10);
	chat_connectUser(chat, user11);

	assert_int_equal(chat_getStatus, CHAT_OVERFLOW);
	chat_free(chat);
}

static void connectAdmin_adminIsConnected_status(void ** state){
	chat_t * chat = chat_new();
	admin_t * admin = user_newAdmin("ADMIN");
	chat_connectAdmin(chat, admin);
	assert_int_equal(chat_getStatus, CHAT_OK);
	chat_free(chat);
}

static void connectUsers_numOfConnectedUsers_zeroCount(void ** state){
	chat_t * chat = chat_new();
	user_t * user1 = user_new("Katya");
	chat_connectUser(chat, user1);
	chat_unconnectUser(chat);
	assert_int_equal(chat_getNumOfUsers(chat), 0);
	chat_free(chat);
}

int runTests(void){
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(numOfUsers_emptyChat_zeroCount),
		cmocka_unit_test(connectUsers_numOfConnectedUsers_oneCount),
		cmocka_unit_test(connectUsers_overflowOfUsers_status),
		cmocka_unit_test(connectAdmin_adminIsConnected_status),
		cmocka_unit_test(connectUsers_numOfConnectedUsers_zeroCount)
	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
