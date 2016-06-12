#define _CRT_SECURE_NO_WARNINGS

#include "server.h"
#include "db.h"

int main(){

	lib_init();

	socket_t * server = socket_new();
	socket_bind(server, 5000);
	socket_listen(server);
	char buf[50000];
	socket_t * client = NULL;

	const char * file = "radio.db";
	db_t * db = db_new(file);

	list_t * list = list_new();
	db_parse(db, list);

	while (1){
		client = socket_accept(server);
		socket_read(client, buf, sizeof(buf));

		if (strlen(buf) != 0){
			puts(buf);
			http_request_t rs;
			rs = http_request_parse(buf);

			if (strcmp(rs.method, "GET") == 0){
				if (strcmp(rs.uri, "/") == 0){
					server_mainPage(client);
				}
				if (strcmp(rs.uri, "/api/radioLead") == 0){  // W
					server_JSON_send(client, radio_JSON_getJsonFromList(list));
				}
				else if (strstr(rs.uri, "/api/radioLead?") != 0){ // W
					server_JSON_send(client, db_task1(db, buf));
				}
				else if (strstr(rs.uri, "/api/radioLead/") != 0){ // W
					int id1;
					int isNumber = sscanf(rs.uri, "/api/radioLead/%d", &id1); 
					if (isNumber){
						radio_t * r = db_getRadioLeadById(db, id1);
						if (NULL == r){
							server_JSON_wrongIndex(client, id1);
						}
						else {
							server_JSON_send(client, radio_JSON_radioLeadToJson(r));
						}
					}
					else server_JSON_wrongIndex(client, id1);
				}
				else if (strcmp(rs.uri, "/radioLead") == 0){
					server_HTML_sendHTMLlist(client, list);  // CHECK!
				}
				else if (strstr(rs.uri, "/radioLead/") != 0){ 
					int id2 = 0;
					int isNum = sscanf(rs.uri, "/radioLead/%d", &id2); 
					if (isNum){
						radio_t * r = server_getRadioLeadById(id2, db);
						if (NULL == r) {
							server_HTML_wrongIndex(client);
						}
						else {
							server_HTML_send(client, radio_getHtml(r, db_getRadioLeadById(db, id2)));
						}
					}
					else server_HTML_wrongIndex(client);
				}
				else if (strcmp(rs.uri, "/new-radioLead") == 0){ //W
					server_HTML_newRadioLeadTable(client);
				}
				else server_notFound(client);
			}
			else if (strcmp(rs.method, "DELETE") == 0){
				if (strstr(rs.uri, "/api/radioLead/") != NULL){
					int id;
					int isNumber = sscanf(rs.uri, "/api/radioLead/%d", &id);
					if (isNumber){
						server_deleteRadioLead(client, list, id, db);
					}
					else{
						server_JSON_wrongIndex(client, id);
					}
				}
				else if (strstr(rs.uri, "/radioLead/") != NULL){
					int id;
					int num = sscanf(rs.uri, "/radioLead/%d", &id);
					if (num){
						server_HTML_deleteRadioLead(client,list, id, db);
					}
					else {
						server_HTML_wrongIndex(client);
					}
				}
			}
			else if (strcmp(rs.method, "POST") == 0){
				if (strcmp(rs.uri, "/api/radioLead") == 0){  //W
					server_addRadioLead(client, list, buf, db);
				}
				else if (strcmp(rs.uri, "/radioLead") == 0) { //W
					server_HTML_addRadioLead(client, list, buf, db);
				}
				else server_notFound(client);
			}
			else if (strcmp(rs.method, "OPTIONS") == 0){
				if (strstr(rs.uri, "/api/radioLead/") != NULL){
					int id;
					int isNumber = sscanf(rs.uri, "/api/radioLead/%d", &id);
					if (isNumber){
						server_deleteRadioLead(client, list, id, db);
					}
					else{
						server_JSON_wrongIndex(client, id);
					}
				}
				else if (strstr(rs.uri, "/radioLead/") != NULL){
					int id;
					int num = sscanf(rs.uri, "/radioLead/%d", &id);
					if (num){
						server_HTML_deleteRadioLead(client, list, id, db);
					}
					else {
						server_HTML_wrongIndex(client);
					}
				}
			}
			else server_notFound(client);
		}
		socket_free(client);
	}

	socket_free(client);
	socket_free(server);
	lib_free();
	return 0;
}

