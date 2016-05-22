#include "nlp.h"

struct text_s{
	char * string;
	int numOfSentences;
	sentence_t * sentences[MAX_AMOUNT_OF_SENTENCES];
};

struct sentence_s{
	char * string;
	int numOfWords;
	word_t * words[MAX_AMOUNT_OF_WORDS];
};

struct word_s{
	char * string;
};

text_t * nlp_newText(char * book){
	text_t * txt = malloc(sizeof(struct text_s));
	txt->numOfSentences = 0; 
	txt->string = malloc((strlen(book + 1)*sizeof(char)));
	strcpy(txt->string, book);
	return txt;

}

void nlp_freeText(text_t * text){
	free(text->string);
	for (int i = 0; i < text->numOfSentences; i++){
		nlp_freeSentence(text->sentences[i]);
	}
	free(text);
}

sentence_t * nlp_newSentence(char * sentence){
	sentence_t * sen = malloc(sizeof(struct sentence_s));
	sen->numOfWords = 0;
	sen->string = malloc(sizeof(char)*strlen(sentence + 1)); 
	strcpy(sen->string, sentence);
	return sen;
}
void nlp_freeSentence(sentence_t * sentence){
	free(sentence->string);
	for (int i = 0; i < sentence->numOfWords; i++){
		nlp_freeWord(sentence->words[i]);
	}
	free(sentence);
}

word_t * nlp_newWord(char * word){
	word_t * wrd = malloc(sizeof(struct word_s));
	wrd->string = malloc(sizeof(char)*(strlen(word+1)));
	strcpy(wrd->string, word);
	return wrd;
}

void nlp_freeWord(word_t * word){
	free(word->string);
	free(word);
}

void nlp_divideToSentences(text_t * text){
	char * copy = malloc((strlen(text->string) + 1) * sizeof(char));
	char * tmp = copy;
	char * delim = strpbrk(copy, "!?.");
	while (delim != NULL){
		char sign = delim[0];
		copy[delim - copy] = '\0';
		char sentence[500];
		sprintf(sentence, "%s%c", copy, sign);
		printf("%s\n", sentence);
		text->sentences[text->numOfSentences] = nlp_newSentence(sentence);
		nlp_divideToWords(text->sentences[text->numOfSentences++]);
		copy += delim - copy + 1;
		while (!isalnum(abs(copy[0]))) copy++;
		delim = strpbrk(delim + 1, ".?!");
	}
	free(tmp);
}
	
void nlp_divideToWords(sentence_t * sentence){
	char * copy = malloc((strlen(sentence->string) + 1)*sizeof(char));
	char * tmp = copy;
	strcpy(copy, sentence->string);
	char * delim = strpbrk(sentence->string, " ");
	while (delim != NULL){
		sentence->words[sentence->numOfWords] = nlp_newWord(delim);
		if (!isalnum(abs(sentence->words[sentence->numOfWords]->string[strlen(sentence->words[sentence->numOfWords]->string) - 1]))){
			sentence->words[sentence->numOfWords]->string[strlen(sentence->words[sentence->numOfWords]->string) - 1] = '\0';
		}
		sentence->numOfWords++;
		delim = strtok(NULL, " ");
	}
	free(tmp);
}

void nlp_printSentences(text_t * text, FILE * outputStream){
	for (int i = 0; i < text->numOfSentences; i++){
		fprintf(outputStream, "%s\n", text->sentences[i]->string);
	}
}

void nlp_printSentencesAndWords(text_t * text, FILE * outputStream){
	for (int i = 0; i < text->numOfSentences; i++){
		fprintf(outputStream, "%s\n", text->sentences[i]->string);
		for (int j = 0; j < text->sentences[i]->numOfWords; j++){
			fprintf(outputStream, "\t%s\n", text->sentences[i]->words[j]->string);
		}
	}
}


