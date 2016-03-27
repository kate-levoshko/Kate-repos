#include "Header.h"
#include "Reader.h"

struct reader_s {
	thread_t * thread;
};

void * Reader(void * args) {
	text_t * text = (text_t *)args;
	while (1) {
		mutex_lock(text->mu);
		if (strlen(text->str) < 5){
			puts(text->str);
		}
		mutex_unlock(text->mu);
		Sleep(1);
	}
	return NULL;
}

reader_t new_reader(text_t * text){
	reader_t reader = (reader_t)malloc(sizeof(struct reader_s));
	reader->thread = thread_create_args(Reader, text);
	return reader;
}

void reader_delete(reader_t reader){
	thread_free(reader->thread);
	free(reader);
}

