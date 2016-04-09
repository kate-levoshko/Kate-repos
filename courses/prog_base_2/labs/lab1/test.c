#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>  
#include <stdarg.h>  
#include <stddef.h>  
#include <setjmp.h>  

#include <cmocka.h>

#include "header.h"

static void createNewHeap_emptyHeap_zeroCount(void ** state){
	heap_t * heap1 = heap_new(5);
	assert_null(heap_amountOfObjects(heap1));
	heap_free(heap1);
}

static void createNewHeap_numberOfProcessLessThanNull_status(void ** state){
	heap_t * heap1 = heap_new(-5);
	assert_int_equal(heap_getStatus(heap1), HEAP_INRORRECTNUMBER);
	heap_free(heap1);
}

static void freeMemory_addAndRemoveSameMemory_statusEmpty(void ** state){
	heap_t * heap1 = heap_new(5);
	heap_addMemory(heap1);
	heap_freeMemory(heap1, 0);
	assert_int_equal(heap_getStatus(heap1), HEAP_EMPTY);
	heap_free(heap1);
}

static void addMemory_hasPointerToStructure_countOne(void ** state){
	heap_t * heap1 = heap_new(5);
	heap_addMemory(heap1);
	assert_int_equal(heap_amountOfObjects(heap1), 1);
	assert_int_equal(heap_getStatus(heap1), HEAP_OK);
	heap_freeMemory(heap1, 0);
	heap_free(heap1);
}

static void freeMemory_incorrectIndex_status(void ** state){
	heap_t * heap1 = heap_new(5);
	heap_freeMemory(heap1, 0);
	heap_freeMemory(heap1, 4);
	assert_int_equal(heap_getStatus(heap1), MEMORY_INCORRECTDATA);
	heap_free(heap1);
}

static void freeMemory_deleteFromEmptyMemory_status(void ** state){
	heap_t * heap1 = heap_new(5);
	heap_freeMemory(heap1, 0);
	assert_int_equal(heap_getStatus(heap1), MEMORY_EMPTY);
	heap_free(heap1);
}

static void addMemory_overflowMemory_status(void ** state){
	heap_t * heap1 = heap_new(5);
	for (int i = 0; i < MAX_AMOUNT_OF_OBJECTS; i++){
		heap_addMemory(heap1);
	}
	assert_true(heap_amountOfObjects(heap1) == MAX_AMOUNT_OF_OBJECTS);
	heap_free(heap1);
}

static void writeBytesInMemory_overflowMemory_status(void ** state){
	heap_t * heap1 = heap_new(5);
	memory_t * mem;
	mem = heap_addMemory(heap1);
	memory_writeBytesInMemory(mem, "0123456789");
	assert_true(strlen("0123456789") + memory_getSize(mem) < MAX_AMOUNT_OF_BYTES);
	heap_free(heap1);
	
}

static void areadBytesfromMemory_hasNoData_status(void **state){
	heap_t * heap1 = heap_new(5);
	memory_t * mem;
	mem = heap_addMemory(heap1);
	assert_null(memory_readBytesfromMemory(mem));
	heap_free(heap1);
}

int runTests(void){
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(createNewHeap_emptyHeap_zeroCount),
		cmocka_unit_test(createNewHeap_numberOfProcessLessThanNull_status),
		cmocka_unit_test(freeMemory_addAndRemoveSameMemory_statusEmpty),
		cmocka_unit_test(addMemory_hasPointerToStructure_countOne),
		cmocka_unit_test(freeMemory_incorrectIndex_status),
		cmocka_unit_test(freeMemory_deleteFromEmptyMemory_status),
		cmocka_unit_test(writeBytesInMemory_overflowMemory_status),
		cmocka_unit_test(areadBytesfromMemory_hasNoData_status)

	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}