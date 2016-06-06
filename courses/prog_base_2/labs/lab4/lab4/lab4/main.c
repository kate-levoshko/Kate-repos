#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <winsock2.h>
#include <windows.h>

#include "server.h"
#include "http.h"

int main(void){

	lib_init();
	char text[TEXT_MAX_SIZE];

	FILE * file = fopen("radio.json", "r");
	fread(text, sizeof(char), TEXT_MAX_SIZE, file);
	cJSON * jObject = cJSON_Parse(text);

	socket_t * server = socket_new();
	socket_bind(server, 5000);
	socket_listen(server);
	char buf[50000];

	socket_t * client = NULL;

	list_t * list = list_new();
	radio_JSON_createList(list, jObject);

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
				if (strcmp(rs.uri, "/api/radioLead") == 0){
					server_JSON_send(client, radio_JSON_getJsonFromList(list));
				}
				else if (strstr(rs.uri, "/api/radioLead/") != 0){
					int id1;
					int isNumber = sscanf(rs.uri, "/api/radioLead/%d", &id1);
					if (isNumber){
						int status = server_JSON_sendById(client, list, id1);
						if (!status) {
							server_JSON_wrongIndex(client, id1);
						}
					}
					else {
						server_JSON_wrongIndex(client, id1);
					}
				}
				else if (strcmp(rs.uri, "/radioLead") == 0){
					server_HTML_sendHTMLlist(client, list);

				}
				else if (strstr(rs.uri, "/radioLead/") != 0){
					int id2 = 0;
					int isNum = sscanf(rs.uri, "/radioLead/%d", &id2);
					if (isNum){
						radio_t * r = radio_getRadioLeadByID(list, id2);
						if (NULL == r) {
							server_HTML_wrongIndex(client);
						}
						else {
							server_HTML_send(client, radio_HTML_radioLeadToHTML(r, radio_getId(r)));
						}
					}
					else server_HTML_wrongIndex(client);
				}
				else if (strcmp(rs.uri, "/new-radioLead") == 0){
					server_HTML_newPupil(client, list);
				}
				else server_notFound(client);
			}
			else if (strcmp(rs.method, "DELETE") == 0) {
				if (strstr(rs.uri, "/api/radioLead/") != NULL){
					int id;
					int isNumber = sscanf(rs.uri, "/api/radioLead/%d", &id);
					if (isNumber){
						int status = server_JSON_deleteRadioLeadById(list, id);
						status ? server_JSON_statusOK(client) : server_JSON_wrongIndex(client, id);

					}
					else {
						server_JSON_deleteError(client);
					}
				}
				else if (strstr(rs.uri, "/radioLead/") != 0){
					int id3;
					int isnum = sscanf(rs.uri, "/radioLead/%d", &id3);
					if (isnum){
						server_HTML_deleteRadioLead(client, list, id3);
					}
					else server_HTML_wrongIndex(client);
				}
				else {
					server_notFound(client);
				}
			}
			else if (strcmp(rs.method, "POST") == 0){
				if (strcmp(rs.uri, "/api/radioLead") == 0){
					if (server_JSON_addRadioLead(client, list, &rs)){
						server_JSON_statusOK(client);
					}
				}
				else if (strcmp(rs.uri, "/radioLead") == 0) {
					server_HTML_addNewRadioLead(client, list, &rs);
				}
				else server_notFound(client);
			}
			else if (strcmp(rs.method, "OPTIONS") == 0){
				if (strstr(rs.uri, "/radioLead/") != 0){
					int id3;
					int isnum = sscanf(rs.uri, "/radioLead/%d", &id3);
					if (isnum){
						server_HTML_deleteRadioLead(client, list, id3);
					}
					else server_HTML_wrongIndex(client);
				}
				else {
					server_notFound(client);
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
