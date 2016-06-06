#include "server.h"

int checkData(char * name, char * surname, char * bithdate, char * jobExperience, char * salary, char * fSong){
	if (!name || !surname || !bithdate || !jobExperience || !salary || !fSong) return 0;
	if (strlen(name) > 25 || strlen(surname) > 50 || strlen(bithdate) > 11 || strlen(fSong) > 50) return 0;
	for (int i = 0; i < strlen(name); i++){
		if (!(isalpha(name[i]) || name[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(surname); i++){
		if (!(isalpha(surname[i]) || surname[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(bithdate); i++){
		if (!(isdigit(bithdate[i]) || bithdate[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(jobExperience); i++){
		if (!(isdigit(jobExperience[i]) || jobExperience[i] == '.')) return 0;
	}

	for (int i = 0; i < strlen(salary); i++){
		if (!isdigit(salary[i])) return 0;
	}

	for (int i = 0; i < strlen(fSong); i++){
		if (!(isalnum(fSong[i]) || jobExperience[i] == '+')) return 0;
	}
	return 1;
}

int server_JSON_send(socket_t * socket, cJSON * data){
	char buffer[5000];
	char * joutput = cJSON_Print(data);
	sprintf(buffer,
		"HTTP/1.1 200 OK\n"
		"Content-Type: application/json\n"
		"Content-Length: %d\n"
		"Connection: keep-alive\r\n\r\n"
		"%s", strlen(joutput), joutput);
	socket_write_string(socket, buffer);
	socket_close(socket);
	return 1;
}

int server_JSON_sendById(socket_t * socket, list_t * list, int id){
	for (int i = 0; i < list_getSize(list); i++){
		radio_t * r = list_get(list, i);
		if (radio_getId(r) == id){
			cJSON * jObj = radio_JSON_radioLeadToJson(r);
			server_JSON_send(socket, jObj);
			return 1;
		}
	}
	return 0;
}

int server_JSON_deleteRadioLeadById(list_t * list, int id){
	for (int i = 0; i < list_getSize(list); i++){
		radio_t * r = list_get(list, i);
		if (radio_getId(r) == id){
			list_remove(list, i);
			return 1;
		}
	}
	return 0;
}

int server_JSON_addRadioLead(socket_t * socket, list_t * list, http_request_t* request){
	int id = radio_getMaxFreeId(list);
	char * name = (char *)http_request_getArg(request, "name");
	char * surname = (char *)http_request_getArg(request, "surname");
	char * birthdate = (char *)http_request_getArg(request, "birthdate");
	char * jobExp = (char *)http_request_getArg(request, "jobExperience");
	char * salary = (char *)http_request_getArg(request, "salary");
	char * favouriteSong = (char *)http_request_getArg(request, "favouriteSong");
	if (checkData(name, surname, birthdate, jobExp, salary, favouriteSong)){
		radio_t * radio = radio_newRadioLead();
		radio_setLeadInfo(radio, id, name, surname, birthdate, atof(jobExp), atoi(salary), favouriteSong);
		list_push_back(list, radio);
		cJSON * rl = radio_JSON_radioLeadToJson(radio);
		server_JSON_send(socket, rl);
		return 1;
	}
	else {
		server_JSON_wrongData(socket);
	return 0;
	}
}

void server_JSON_notFound(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("404! Page not found!"));
	server_JSON_send(socket, obj);
}

void server_JSON_wrongIndex(socket_t * socket, int id){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("Wrong Index!"));
	server_JSON_send(socket, obj);
}

void server_JSON_statusOK(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("Everything is OK!"));
	server_JSON_send(socket, obj);
}

void server_JSON_deleteError(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("Deleting error"));
	server_JSON_send(socket, obj);
}

void server_JSON_wrongData(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("Wrong Data!"));
	server_JSON_send(socket, obj);
}

void server_HTML_send(socket_t * socket, char * text){
	char buffer[10000];
	sprintf(buffer,
		"HTTP/1.1 %s\n"
		"Content-Type: text/html\n"
		"Content-Length: %d\n"
		"Connection: keep-alive\r\n\r\n"
		"\n%s", "200 OK", strlen(text) + 1, text);
	socket_write_string(socket, buffer);
	socket_close(socket);
	
}

void server_HTML_sendHTMLlist(socket_t * socket, list_t * radioLeads){
	char html[5000] = "<html>"
						"<head>"
							"<title>Radio Leads</title>"
							"<h1><b><mark>List of Radio Leads:</mark></b></h1>"
									"<body>"
										"<ul>"
											"<ul>";
	for (int i = 0; i< list_getSize(radioLeads); i++){
		char radioLead[100];
		radio_t * radio = list_get(radioLeads, i);
		sprintf(radioLead, "<li><a href= http://localhost:5000/radioLead/%d> %s %s</a></li>", radio_getId(radio), radio_getName(radio), radio_getSurname(radio));
		strcat(html, radioLead);
	}
	strcat(html, "</ul></ul></body></head></html>");
	server_HTML_send(socket, html);
}

void server_mainPage(socket_t * socket){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("main_page.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	free(buffer);
}

void server_HTML_newPupil(socket_t * client, list_t * pupils){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("table.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(client, buffer);
	free(buffer);
}

void server_HTML_deleteRadioLead(socket_t * socket, list_t * radioLead, int id){
	if (radio_deleteRadioLeadById(radioLead, id)){
		server_HTML_sendHTMLlist(socket, radioLead);
	}
	else server_HTML_wrongIndex(socket);
}

int server_HTML_addNewRadioLead(socket_t * socket, list_t * list, http_request_t* request){

	int id = radio_getMaxFreeId(list);
	char * name = (char *)http_request_getArg(request, "name");
	char * surname = (char *)http_request_getArg(request, "surname");
	char * birthdate = (char *)http_request_getArg(request, "birthdate");
	char * jobExp = (char *)http_request_getArg(request, "jobExperience");
	char * salary = (char *)http_request_getArg(request, "salary");
	char * favouriteSong = (char *)http_request_getArg(request, "favouriteSong");
	if (checkData(name, surname, birthdate, jobExp, salary, favouriteSong)){
		radio_t * radio = radio_newRadioLead();
		radio_setLeadInfo(radio, id, name, surname, birthdate, atof(jobExp), atoi(salary), favouriteSong);
		list_push_back(list, radio);

		server_HTML_send(socket, radio_HTML_radioLeadToHTML(radio, radio_getId(radio)));
		return 1;

	}
	else {
		server_HTML_wrongData(socket);
		return 0;
	}
}

void server_HTML_wrongData(socket_t * socket){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("wrong_data.html", "r"); 
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	free(buffer);
}


void server_HTML_wrongIndex(socket_t * socket){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("wrong_index.html", "r"); 
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	free(buffer);
}


void server_notFound(socket_t * client){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("not_found.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(client, buffer);
	free(buffer);
}





