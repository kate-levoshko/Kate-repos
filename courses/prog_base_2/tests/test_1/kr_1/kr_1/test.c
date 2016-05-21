#include <stdio.h>
#include <string.h>

#include <stdlib.h>  
#include <stdarg.h>  
#include <stddef.h>  
#include <setjmp.h>  

#include <cmocka.h>

#include "radio.h"

static void addTrack_oneTrack_oneCount(void ** state){
	radio_t * r1 = radio_new();
	trackList_t * trackList = radio_newTrackList(1);
	track_t t1 = radio_newTrack();
	radio_addTrack(trackList, t1);
	assert_int_equal(radio_getNumOfTracks, 1);
	radio_trackListFree(trackList);
	radio_free(r1);
}

int test(void){
	const struct CMUnitTest tests[] =
	{
		cmocka_unit_test(addTrack_oneTrack_oneCount)

	};
	return cmocka_run_group_tests(tests, NULL, NULL);
}

