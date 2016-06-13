#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

typedef struct tv_s tv_t;
typedef struct viewer_s viewer_t;
typedef struct video_s video_t;

enum VideoStatus{
	FILM,
	ADVERTISEMENT
};

enum ViewerStatus{
	ACTIVE,
	PASSIVE
};


tv_t * tv_new();
viewer_t * tv_newViewer(tv_t * self, char * name, enum ViewerStatus type);
video_t * tv_newVideo(enum VideoStatus type, char * name);
void tv_free(tv_t * self);
void tv_freeViewer(viewer_t * self);
void tv_freeVideo(video_t * self);


void tv_addVideo(tv_t * self, video_t * video);
video_t * tv_getCurVideoInf(tv_t * self, video_t * copy);
void tv_deleteVideo(tv_t * self, int index);
list_t * tv_getVideoList(tv_t * self);


int tv_getAmountOfVideos(tv_t * self);
void tv_addViewer(tv_t *self, viewer_t * view);
void tv_deleteViewer(tv_t * self, int index);
int tv_getViewerTypeCount(tv_t * self);

enum VideoStatus tv_getVideoType(video_t * video);
enum ViewerStatus tv_getViewerType(viewer_t * viewer);

