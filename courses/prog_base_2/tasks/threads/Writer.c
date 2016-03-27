#include "Header.h"
#include "Writer.h"

struct writer_s {
	thread_t * thread;
};

void * Writer(void * args) {
	text_t * text = (text_t *)args;
	while (1) {
		mutex_lock(text->mu);
		text->str = text->strings[text->number++];
		if (text->number == AMOUNT_OF_STRINGS){
			text->number = 0;
		}
		mutex_unlock(text->mu);
	}
	return NULL;
}

writer_t new_writer(text_t * text){
	writer_t writer = (writer_t)malloc(sizeof(struct writer_s));
	writer->thread = thread_create_args(Writer, text);
	return writer;
}

void writer_delete(writer_t writer){
	thread_free(writer->thread);
	free(writer);
}

