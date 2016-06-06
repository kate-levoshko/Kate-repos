#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "socket.h"
#include "radio.h"
#include "http.h"

#define LINE_MAX_SIZE 100
#define TEXT_MAX_SIZE 10000


#include "server.h"

int checkData(char * name, char * surname, char * bithdate, char * jobExperience, char * salary, char * fSong);
int server_JSON_send(socket_t * socket, cJSON * data);
int server_JSON_sendById(socket_t * socket, list_t * list, int id);;
int server_JSON_deleteRadioLeadById(list_t * list, int id);
int server_JSON_addRadioLead(socket_t * socket, list_t * list, http_request_t* request);
void server_JSON_wrongIndex(socket_t * socket, int id);
void server_JSON_statusOK(socket_t * socket);
void server_JSON_deleteError(socket_t * socket);
void server_JSON_wrongData(socket_t * socket);
void server_HTML_send(socket_t * socket, char * text);
void server_HTML_sendInputPage(socket_t * socket, http_request_t * request);
void server_HTML_sendHTMLlist(socket_t * socket, list_t * radioLeads);
void server_HTML_deleteRadioLead(socket_t * socket, list_t * radioLeads, int id);
void server_openPage(socket_t * client);
int server_HTML_addNewRadioLead(socket_t * socket, list_t * list, http_request_t* request);
void server_HTML_wrongData(socket_t * socket);
void server_HTML_wrongIndex(socket_t * socket);

void server_HTML_newPupil(socket_t * client, list_t *list);
void server_notFound(socket_t * client);
void server_mainPage(socket_t * socket);


