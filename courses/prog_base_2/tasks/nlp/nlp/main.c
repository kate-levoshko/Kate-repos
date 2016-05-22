#define _CRT_SECURE_NO_WARNINGS

#include "nlp.h"

int main(){

	char book[6000];

	FILE * txtFile = fopen("text.txt", "r");
	fread(book, sizeof(char), 6000, txtFile);

	text_t * text = nlp_newText(book);
	nlp_divideToSentences(text);

	FILE * sentFile = fopen("sentences.txt", "w");
	FILE * wordsFile = fopen("words.txt", "w");

	nlp_printSentences(text, sentFile);
	nlp_printSentencesAndWords(text, wordsFile);


	nlp_freeText(text);

	fclose(sentFile);
	fclose(wordsFile);

	getchar();
	return EXIT_SUCCESS;
}
