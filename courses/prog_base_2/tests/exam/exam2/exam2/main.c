#include "tv.h"

int main(void){
	tv_t * tv = tv_new();
	viewer_t *v1 =  tv_newViewer(tv, "Katya", ACTIVE);
	viewer_t *v2 = tv_newViewer(tv, "Lina", PASSIVE);
	viewer_t *v3 = tv_newViewer(tv, "Karina", ACTIVE);

	video_t * video1 = tv_newVideo(ADVERTISEMENT, "Children");

	tv_addViewer(tv, v1);
	tv_addViewer(tv, v2);
	tv_addViewer(tv, v3);
	printf("%d", tv_getViewerTypeCount(tv));
	

	tv_freeVideo(video1);
	tv_freeViewer(v1);
	tv_freeViewer(v2);
	tv_freeViewer(v3);
	tv_free(tv);
	getchar();
	return 0;
}