#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libxml/parser.h>
#include <libxml/tree.h>

#define LINE_MAX_SIZE 100
#define TEXT_MAX_SIZE 1000
#define MAX_NUMBER_OF_LEADS 100

typedef struct radio_s radio_t;
typedef struct radioLead_s radioLead_t;

radio_t * radio_newRadio(void);
void radio_free(radio_t * self);

radioLead_t * radioLead_newRadioLead(void);
void radioLead_free(radioLead_t * self);

void radio_parseXML(radio_t * self);




