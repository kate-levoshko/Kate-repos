#define _CRT_SECURE_NO_WARNINGS

#include "cJSON.h"
#include "list.h"

typedef struct radio_s radio_t;

radio_t * radio_newRadioLead(void);
void radio_free(radio_t * self);
void radio_setLeadInfo(	radio_t * radioLead,
						int id,
						char * name,
						char * surname,
						char * birthdate,
						double jobExp,
						int salary,
						char * favouriteSong);

void radio_JSON_createList(list_t * list, cJSON * radioLeads);
cJSON * radio_JSON_getJsonFromList(list_t * list);
cJSON * radio_JSON_radioLeadToJson(radio_t * radioLead);
char * radio_HTML_radioLeadToHTML(radio_t * radioLead, int id);
radio_t * radio_getRadioLeadByID(list_t * list, int id);
int radio_getMaxFreeId(list_t * radioLead);
int radio_deleteRadioLeadById(list_t * radioLeads, int id);

int radio_getId(radio_t* radio);
char * radio_getName(radio_t * radio);
char * radio_getSurname(radio_t * radio);
char * radio_getBirthdate(radio_t * radio);
double radio_getJobExperiense(radio_t * radio);
int radio_getSalary(radio_t * radio);
char * radio_getFavouriteSong(radio_t * radio);
