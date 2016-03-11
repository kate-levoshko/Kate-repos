#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>  // !
#include <stdarg.h>  // !
#include <stddef.h>  // !
#include <setjmp.h>  // !

#include <cmocka.h>

#include "post.h"

static void createNewList_void_zeroCount(void **state){
	list_t * list = list_new();
	assert_int_equal(list_getSize(list), 0);
	list_free(list);
}

static void addPostByIndex_hasOneValue_countOne(void **state){
	list_t * list = list_new();
	list_setPostAt(list, 0, "Dance");
	assert_int_equal(list_getSize(list), 1);
	list_free(list);
}

static void addPostByIndex_hasIncorrectIndex_status(void **state){
	list_t * list = list_new();
	list_setPostAt(list, -3, "Imagination");
	assert_int_equal(list_getStatus(list), WRONG_INDEX);
	list_free(list);
}

static void addPostByIndex_hasNegativeIndex_status(void **state){
	list_t * list = list_new();
	list_setPostAt(list, -3, "Imagination");
	assert_int_equal(list_getStatus(list), WRONG_INDEX);
	list_free(list);
}

static void addPostByIndex_hasOverflowIndex_status(void **state){
	list_t * list = list_new();
	list_setPostAt(list, 999, "Imagination");
	assert_int_equal(list_getStatus(list), WRONG_INDEX);
	list_free(list);
}

static void removePostByIndex_addAndRemoveSamePost_countZero(void **state){
	list_t * list = list_new();
	list_setPostAt(list, 0, "Dance");
	list_postRemove(list, 0);
	assert_int_equal(list_getSize(list), 0);
	list_free(list);
}

static void removePostByIndex_incorrectAction_status(void **state){
	list_t * list = list_new();
	list_postRemove(list, 0);
	assert_int_equal(list_getStatus(list), LIST_EMPTY);
	list_free(list);
}

static void compareRandomValWithNumOfReposts_negativeValue_status(void **state){
	list_t * list = list_new();
	list_listOfPosts(list, -777);
	assert_int_equal(list_getStatus(list), INCORRECT_AMOUNT);
	list_free(list);
}

int main(void){
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(createNewList_void_zeroCount),
		cmocka_unit_test(addPostByIndex_hasOneValue_countOne),
		cmocka_unit_test(addPostByIndex_hasNegativeIndex_status),
		cmocka_unit_test(addPostByIndex_hasOverflowIndex_status),
		cmocka_unit_test(removePostByIndex_addAndRemoveSamePost_countZero),
		cmocka_unit_test(removePostByIndex_incorrectAction_status),
		cmocka_unit_test(compareRandomValWithNumOfReposts_negativeValue_status)

	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}
