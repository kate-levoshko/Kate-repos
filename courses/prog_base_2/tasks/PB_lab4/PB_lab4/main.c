#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>
#include "radio.h"

int main(){
	radio_t *  radio1 = radio_newRadio();
	radio_parseXML(radio1);
	radio_free(radio1);
	getchar();
	return 0;
}