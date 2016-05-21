#include "radio.h"

struct track_s{
	char * name;
	double length;
};

struct trackList_s{
	track_t * arr;
	int length;
	enum ListStatus list_status;
};

struct radio_s{
	char * name;
	trackList_t * tracks[MAX_AMOUNT_OF_TRACKS];
	enum RadioError status;  
	enum RadioState state;	
};

track_t radio_newTrack(void){
	track_t t = (radio_t *)malloc(sizeof(struct track_s));
	t->length = 0;
	return t;
}

trackList_t * radio_newTrackList(int capacity){
	trackList_t * Tracklist = malloc(sizeof(struct trackList_s));
	Tracklist->arr = malloc(capacity*sizeof(trackList_t));
	Tracklist->length = 0;
}

void radio_trackListFree(trackList_t * self){
	free(self->arr);
	free(self);
}

radio_t * radio_new(void){
	radio_t * r = (radio_t *)malloc(sizeof(struct radio_s));
	r->state = RADIO_WORK;
	return r;
}

void radio_free(radio_t * radio){
	free(radio);
}

enum RadioError radio_getStatus(radio_t * radio){
	return radio->status;
}
enum RadioState radio_getState(radio_t * radio){
	return radio->state;
}

int radio_getNumOfTracks(trackList_t * trackList){
	return trackList->length;
}

void radio_changeName(radio_t * radio, char * name){
	radio->name = name;
}

char * radio_getName(radio_t * radio){
	return radio->name;
}

void radio_addTrack(trackList_t * self, track_t data){
	self->arr[self->length++] = data;

}

void radio_trackDelete(trackList_t * self, int index){
	if (index >= self->length || index < 0) exit(EXIT_SUCCESS);
	for (int i = index; i < self->length - 1; i++){
		self->arr[i] = self->arr[i + 1];
	}
	self->length--;
}

int radio_length(trackList_t * self){
	return self->length;
}




