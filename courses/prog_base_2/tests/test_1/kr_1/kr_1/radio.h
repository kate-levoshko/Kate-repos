#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listener.h"

#define MAX_AMOUNT_OF_TRACKS 100

typedef struct radio_s radio_t;
typedef struct track_s * track_t;
typedef struct trackList_s trackList_t;

enum ListStatus{
	LIST_WRONG_INDEX,
	LIST_OK
};

enum RadioError{
	RADIO_OK,
	RADIO_ERROR
};

enum RadioState{
	RADIO_WORK,
	RADIO_PAUSE
};

track_t radio_newTrack(void);

trackList_t * radio_newTrackList(int capacity);

void radio_trackListFree(trackList_t * self);

radio_t * radio_new(void);

void radio_free(radio_t * radio);

enum RadioError radio_getStatus(radio_t * radio);
enum RadioState radio_getState(radio_t * radio);
int radio_getNumOfTracks(trackList_t * trackList);
void radio_changeName(radio_t * radio, char * name);

char * radio_getName(radio_t * radio);
void radio_addTrack(trackList_t * self, track_t data);
void radio_trackDelete(trackList_t * self, int index);

int radio_length(trackList_t * self);

