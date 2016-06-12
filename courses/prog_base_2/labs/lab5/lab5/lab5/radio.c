
#include "radio.h"

struct radio_s{
	int id;
	char name[256];
	char surname[256];
	char birthdate[256];
	int salary;
	double jobExp;
	int prorgams;
};

radio_t * radio_newRadioLead(void){
	radio_t * radio = (radio_t *)malloc(sizeof(struct radio_s));
	radio->id = 0;
	return radio;
}

void radio_free(radio_t * self){
	free(self);
}

void radio_setLeadInfo(	radio_t * radioLead,
						int id,
						char * name,
						char * surname,
						char * birthdate,
						int salary,
						double jobExp,
						int programs){

	radioLead->id = id;
	strcpy(radioLead->name, name);
	strcpy(radioLead->surname, surname);
	strcpy(radioLead->birthdate, birthdate);
	radioLead->salary = salary;
	radioLead->jobExp = jobExp;
	radioLead->prorgams = programs;
}

void radio_JSON_createList(list_t * list, cJSON * radioLeads){
	for (int i = 0; i < cJSON_GetArraySize(radioLeads); i++){
		cJSON * radioLead = cJSON_GetArrayItem(radioLeads, i);
		cJSON * id = cJSON_GetObjectItem(radioLead, "id");
		cJSON * name = cJSON_GetObjectItem(radioLead, "name");
		cJSON * surname = cJSON_GetObjectItem(radioLead, "surname");
		cJSON * birthdate = cJSON_GetObjectItem(radioLead, "birthdate");
		cJSON * salary = cJSON_GetObjectItem(radioLead, "salary");
		cJSON * jobExp = cJSON_GetObjectItem(radioLead, "jobExperience");
		cJSON * programs = cJSON_GetObjectItem(radioLead, "programs");

		radio_t * rl1 = radio_newRadioLead();
		radio_setLeadInfo(	rl1, id->valueint, name->valuestring, surname->valuestring, birthdate->valuestring,
							salary->valueint, jobExp->valuedouble, programs->valueint);

		list_push_back(list, rl1);
	}
}

cJSON * radio_JSON_radioLeadToJson(radio_t * radioLead){

	cJSON * RadioLead = cJSON_CreateObject();

	cJSON_AddItemToObject(RadioLead, "id", cJSON_CreateNumber(radioLead->id));
	cJSON_AddItemToObject(RadioLead, "name", cJSON_CreateString(radioLead->name));
	cJSON_AddItemToObject(RadioLead, "surname", cJSON_CreateString(radioLead->surname));
	cJSON_AddItemToObject(RadioLead, "birthdate", cJSON_CreateString(radioLead->birthdate));
	cJSON_AddItemToObject(RadioLead, "salary", cJSON_CreateNumber(radioLead->salary));
	cJSON_AddItemToObject(RadioLead, "jobExperience", cJSON_CreateNumber(radioLead->jobExp));
	cJSON_AddItemToObject(RadioLead, "programs", cJSON_CreateNumber(radioLead->prorgams));
	
	return RadioLead;
}

cJSON * radio_JSON_getJsonFromList(list_t * list){
	cJSON * arr = cJSON_CreateArray();
	for (int i = 0; i < list_getSize(list); i++){
		radio_t * radioLead = list_get(list, i);
		cJSON * rl = radio_JSON_radioLeadToJson(radioLead);
		cJSON_AddItemToArray(arr, rl);
	}
	return arr;
}

char * radio_getHtml(radio_t * radio, int id){
	char buff[50000] = "\0";

	char text[1024] = "";
	sprintf(text,
		"<p>"
		"<a href ='/radioLead'>Back to RadioLeads</a><br>"
		"Id: %d<br>"
		"Name: %s<br>"
		"Surname: %s<br>"
		"Birthdate: %s<br>"
		"Salary: %d<br>"
		"Job Experience: %.2f<br>"
		"Programs: %d<br>"
		"</p>",
		radio->id, radio->name, radio->surname, radio->birthdate, radio->salary, radio->jobExp, radio->prorgams);
	strcat(buff, text);

	char * pageTextLink = "<a href=\"#\" onclick=\"doDelete()\"/>Delete RadioLead<br><br></a>\n";
	strcat(buff, pageTextLink);

	char pageTextScript[1024];
	sprintf(pageTextScript,
		"<script>"
		"function doDelete() {"
		"var xhttp = new XMLHttpRequest();"
		"xhttp.open(\"DELETE\", \"http://127.0.0.1:5000/radioLead/%d\", true);"
		"xhttp.send();"
		"window.location='/radioLead'"
		"}"
		"</script> ", id);
	strcat(buff, pageTextScript);

	return buff;
}

radio_t * radio_getRadioLeadByID(list_t * list, int id){
	for (int i = 0; i < list_getSize(list); i++){
		radio_t * radioLead = list_get(list, i);
		if (radioLead->id == id){
			return radioLead;
		}
	}
	return NULL;
}

int radio_deleteRadioLeadById(list_t * radioLeads, int id){
	for (int i = 0; i < list_getSize(radioLeads); i++){
		radio_t * radio = list_get(radioLeads, i);
		if (radio_getId(radio) == id){
			list_remove(radioLeads, i);
			return 1;
		}
	}
	return 0;
}

int radio_getMaxFreeId(list_t * radioLead){
	int maxID = 0;
	for (int i = 0; i < list_getSize(radioLead); i++){
		radio_t * radio = list_get(radioLead, i);
		if (radio_getId(radio) > maxID){
			maxID = radio_getId(radio);
		}
	}
	return maxID + 1;
}

int radio_getId(radio_t * radio){
	return radio->id;
}

char * radio_getName(radio_t * radio){
	return radio->name;
}

char * radio_getSurname(radio_t * radio){
	return radio->surname;
}

char * radio_getBirthdate(radio_t * radio){
	return radio->birthdate;
}

double radio_getJobExperiense(radio_t * radio){
	return radio->jobExp;
}

int radio_getSalary(radio_t * radio){
	return radio->salary;
}


