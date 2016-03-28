#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include "Writer.h"
#include "Reader.h"


int main(){

	text_t data;

	for (int i = 0; i < AMOUNT_OF_STRINGS; i++){
		data.strings[i] = (char *)malloc(MAX_AMOUNT_OF_LETTERS*sizeof(char));
	}

	data.mu = mutex_new();
	data.number = 0;
	data.str = data.strings[0];

	strcpy(data.strings[0], "word1");
	strcpy(data.strings[1], "word2");
	strcpy(data.strings[2], "word3");
	strcpy(data.strings[3], "kpi");
	strcpy(data.strings[4], "hell");
	strcpy(data.strings[5], "word6");
	strcpy(data.strings[6], "word7");
	strcpy(data.strings[7], "word8");
	strcpy(data.strings[8], "word9");
	strcpy(data.strings[9], "Ruslan");

	reader_t setter1 = new_reader(&data);
	writer_t getter1 = new_writer(&data);
	writer_t getter2 = new_writer(&data);

	reader_delete(setter1);
	writer_delete(getter1);
	writer_delete(getter2);

	mutex_free(data.mu);
	return 0;
}
