#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "tv.h"
/*
1.Додати відео у список відтворення(2 види: фільм або реклама) //
2.Отримати інформацію про поточне відео(назва, тип, тощо) //
3.Видалити відео зі списку відтворення //
4.Переключити відео на наступне ?
5.Отримати кількість та список відео відтворення //
6.Додати глядача ТВ зі списку глядачів //
7.Видалити глядача ТВ зі списку глядачів  //
8.Отримати кількість активних глядачів  //
9.Отримати історію підключення та відключення глядачів від онлайн ТВ. 
*/




struct tv_s{
	int curVideo;
	int numOfVideos;
	int numOfViewers;
	list_t * video;
	list_t * viewer;
};

struct video_s{
	enum VideoStatus type;
	char name[100];
};

struct viewer_s{
	enum ViewerStatus type;
	char name[100];
};

tv_t * tv_new(){
	tv_t * tv = malloc(sizeof(struct tv_s));
	tv->numOfViewers = 0;
	tv->numOfVideos = 0;
	tv->curVideo = 0;
	tv->video = list_new();
	tv->viewer = list_new();
	return tv;
}

viewer_t * tv_newViewer(tv_t * self, char * name, enum ViewerStatus type){
	viewer_t * v = malloc(sizeof(struct viewer_s));
	strcpy(v->name, name);
	return v;
}

video_t * tv_newVideo(enum VideoStatus type, char * name){
	video_t * video = malloc(sizeof(struct video_s));
	video->type = type;
	strcpy(video->name, name);
	return video;
}

void tv_free(tv_t * self){
	list_free(self->video);
	list_free(self->viewer);
	free(self);
}

void tv_freeViewer(viewer_t * self){
	free(self);
}

void tv_freeVideo(video_t * self){
	free(self);
}


void tv_addVideo(tv_t * self, video_t * video){ //1
	list_push_back(self->video, video);
	self->numOfVideos++;
}

video_t * tv_getCurVideoInf(tv_t * self, video_t * copy){ //2
	strcpy(copy->name, ((video_t*)list_get(self->video, self->curVideo))->name);
	copy->type = ((video_t*)list_get(self->video, self->curVideo))->type;
	return copy;
}

void tv_deleteVideo(tv_t * self, int index){ //3
	if (list_getSize(self->video) == 0)
		return;
	list_remove(self->video, index);
	self->numOfVideos--;
}

list_t * tv_getVideoList(tv_t * self){  //5
	list_t * copy = list_new_copy(self->video);
	return copy;
}

int tv_getAmountOfVideos(tv_t * self){ //5
	return self->numOfVideos;
}

void tv_addViewer(tv_t *self, viewer_t * view){ //6
	list_push_back(self->viewer, view);
	self->numOfViewers++;
}

void tv_deleteViewer(tv_t * self, int index){ //7
	list_remove(self->viewer, index);
	self->numOfViewers--;
}

int tv_getViewerTypeCount(tv_t * self){  //8
	int count = 0;
	for (int i = 0; i < self->numOfViewers; i++){
		if (tv_getViewerType(self->viewer) == ACTIVE){
			count++;
		}
	}
	return count;
}

enum VideoStatus tv_getVideoType(video_t * video){
	return video->type;
}

enum ViewerStatus tv_getViewerType(viewer_t * viewer){
	return viewer->type;
}





