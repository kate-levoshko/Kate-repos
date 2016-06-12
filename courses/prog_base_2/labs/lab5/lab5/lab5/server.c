#include "server.h"

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

void server_JSON_deleteRadioLeadById(socket_t * socket, list_t * list, db_t * db, int id){
	if (db_deleteRadioLeadById(db, list, id)){
		server_JSON_successDeelting(socket);
	}
	else {
		server_JSON_deleteError(socket);
	}
}

int server_JSON_addRadioLead(socket_t * socket, list_t * list, http_request_t* request){

	int id = radio_getMaxFreeId(list);

	char * name = (char *)http_request_getArg(request, "name");
	char * surname = (char *)http_request_getArg(request, "surname");
	char * birthdate = (char *)http_request_getArg(request, "birthdate");
	char * salary = (char *)http_request_getArg(request, "salary");
	char * jobExp = (char *)http_request_getArg(request, "jobExperience");
	char * programs = (char *)http_request_getArg(request, "programs");
	if (checkData(name, surname, birthdate, salary, jobExp, programs)){
		radio_t * radio = radio_newRadioLead();
		radio_setLeadInfo(radio, id, name, surname, birthdate, atoi(salary), atof(jobExp), atoi(programs));
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



void server_HTML_deleteRadioLead(socket_t * client, list_t * list, int id, db_t * self){
	if (db_deleteRadioLeadById(self, list, id) == 1){
		server_HTML_sendHTMLlist(client, list);
	}
	else {
		server_HTML_wrongIndex(client);
	}
}

void server_HTML_addRadioLead(socket_t * client, list_t * list, char * buf, db_t * db){
	http_request_t req = http_request_parse(buf);
	
	char * name = (char *)http_request_getArg(&req, "name");
	char * surname = (char *)http_request_getArg(&req, "surname");
	char * birthdate = (char *)http_request_getArg(&req, "birthdate");
	char * salary = (char *)http_request_getArg(&req, "salary");
	char * jobExp = (char *)http_request_getArg(&req, "jobExperience");
	char * programs = (char *)http_request_getArg(&req, "programs");

	//if (checkData(name, surname, birthdate, salary, jobExp, programs)){
		radio_t * r = radio_newRadioLead();
		int id = db_getNewId(db);
		radio_setLeadInfo(r, id, name, surname, birthdate, atoi(salary), atof(jobExp), atoi(programs));
		list_push_back(list, r);
		db_addRadioLead(db, list, buf);
		server_HTML_send(client, radio_getHtml(r, id));
	//}
	//else {
		//server_HTML_wrongData(client);
	//}
}


void server_addRadioLead(socket_t * client, list_t * list, char * buf, db_t * self){
	int status = db_addRadioLead(self, list, buf);
	if (status == 0){
		server_notFound(client);
	}
	else if (status == -1){
		server_HTML_wrongData(client);
	}

}

void server_HTML_sendTable(socket_t * socket, db_t * self){
	char html[5000] = "<html>"
						"<head>"
						"<style>"
							"th {"
									"font-family:'Century Gothic';"
									"font-size:30px;"
									"align : center;"
								"}"
						"</style>"
						"<title>Radio</title>"
						"</head>"
						"<body>"
						"<table bgcolor='#ccccff' cellpadding='2' cellspacing='0' border='4' bordercolor='#cc66cc' align='center' width='70%'>"
						"<tr>"
						"<th>ID</th>"
						"<th>Name</th>"
						"<th>Surname</th>"
						"<th>birthdate</th>"
						"<th>salary</th>"
						"<th>JobExp</th>"
						"<th>Programs</th>"
						"</tr>";


	const char * sqlQuery = "SELECT * FROM Radio";
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL); 

	while (1){
		int rc = sqlite3_step(stmt);
		if (SQLITE_ERROR == rc) {
			return;
		}
		else if (SQLITE_ROW == rc){
			char tr[500] = "<tr>";
			int count = sqlite3_column_count(stmt);
			for (int i = 0; i < count; i++){
				char * text = sqlite3_column_text(stmt, i);
				char td[500] = "";
				sprintf(td, "<td>%s</td>", text);
				strcat(tr, td);
			}
			strcat(tr, "</tr>");
			strcat(html, tr);
		}
		else if (SQLITE_DONE == rc) {
			break;
		}
	}
	strcat(html, "</table></body></html>");
	server_HTML_send(socket, html);
}


radio_t * server_getRadioLeadById(int id, db_t * self){
	return db_getRadioLeadById(self, id);
}

void server_deleteRadioLead(socket_t * client, list_t * list, int id, db_t * self){
	if (db_deleteRadioLeadById(self, list, id) == 1){
		cJSON *jResp = cJSON_CreateObject();
		cJSON_AddItemToObject(jResp, "status", cJSON_CreateString("Deleted"));
		server_JSON_send(client, jResp);
	}
	else server_JSON_wrongIndex(client, id);
}




int checkData(char * name, char * surname, char * bithdate, char * salary, char * jobExperience, char * programs){
	if (!name || !surname || !bithdate || !jobExperience || !salary || !programs) return 0;
	if (strlen(name) > 25 || strlen(surname) > 50 || strlen(bithdate) > 11) return 0;
	for (int i = 0; i < strlen(name); i++){
		if (!(isalpha(name[i]) || name[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(surname); i++){
		if (!(isalpha(surname[i]) || surname[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(bithdate); i++){
		if (!(isdigit(bithdate[i]) || bithdate[i] == '-')) return 0;
	}

	for (int i = 0; i < strlen(salary); i++){
		if (!isdigit(salary[i])) return 0;
	}

	for (int i = 0; i < strlen(jobExperience); i++){
		if (!(isdigit(jobExperience[i]) || jobExperience[i] == '.')) return 0;
	}

	for (int i = 0; i < strlen(programs); i++){
		if (!(isdigit(programs[i]))) return 0;
	}
	return 1;
}

void server_JSON_notFound(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("404! Page not found!"));
	server_JSON_send(socket, obj);
}

void server_JSON_successDeelting(socket_t * socket){
	cJSON * obj = cJSON_CreateObject();
	cJSON_AddItemToObject(obj, "status", cJSON_CreateString("RadioLead is deleted!"));
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

void server_HTML_wrongData(socket_t * socket){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("wrong_data.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	fclose(file);
	free(buffer);
}

void server_HTML_wrongIndex(socket_t * socket){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("wrong_index.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	fclose(file);
	free(buffer);
}

void server_notFound(socket_t * client){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("not_found.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(client, buffer);
	fclose(file);
	free(buffer);
}

void server_mainPage(socket_t * socket){
	char buffer[50000] = "";
	FILE * file = fopen("main_page.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(socket, buffer);
	fclose(file);
}

void server_HTML_newRadioLeadTable(socket_t * client){
	char * buffer = malloc(sizeof(char)* 10000);
	FILE * file = fopen("table.html", "r");
	int size = fread(buffer, sizeof(char), 10000, file);
	buffer[size] = '\0';
	server_HTML_send(client, buffer);
	fclose(file);
	free(buffer);
}
