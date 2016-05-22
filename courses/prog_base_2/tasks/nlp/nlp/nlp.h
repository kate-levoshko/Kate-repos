#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_AMOUNT_OF_SENTENCES 500
#define MAX_AMOUNT_OF_WORDS 2000

typedef struct text_s text_t;
typedef struct sentence_s sentence_t;
typedef struct word_s word_t;

text_t * nlp_newText(char * book);
void nlp_freeText(text_t * text);

sentence_t * nlp_newSentence(char * string);
void nlp_freeSentence(sentence_t * sentence);

word_t * nlp_newWord(char * string);
void nlp_freeWord(word_t * word);

void nlp_divideToSentences(text_t * text);
void nlp_divideToWords(sentence_t * sentence);
void nlp_printSentences(text_t * text, FILE * outputStream);
void nlp_printSentencesAndWords(text_t * text, FILE * outputStream);
