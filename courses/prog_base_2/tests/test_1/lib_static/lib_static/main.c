#include "radio.h"


int main(void){
	radio_t * radio1 = radio_new();
	radio_changeName(radio1, "RADIO");
	printf("%s\n", radio_getName(radio1));
	track_t t1 = radio_newTrack();
	track_t t2 = radio_newTrack();
	track_t t3 = radio_newTrack();
	track_t t4 = radio_newTrack();
	trackList_t * trackList = radio_newTrackList(5);
	radio_addTrack(trackList, t1);
	radio_addTrack(trackList, t2);
	radio_addTrack(trackList, t3);
	radio_addTrack(trackList, t4);
	radio_trackDelete(trackList, 0);
	printf("%d\n", radio_length(trackList));
	radio_trackListFree(trackList);
	radio_free(radio1);
	
	getchar();
	return 0;
	}