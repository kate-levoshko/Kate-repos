#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <ctype.h>

#include "socket.h"
#include "db.h"

#define LINE_MAX_SIZE 100
#define TEXT_MAX_SIZE 10000

#include "server.h"

int server_JSON_send(socket_t * socket, cJSON * data);
int server_JSON_sendById(socket_t * socket, list_t * list, int id);
void server_JSON_deleteRadioLeadById(socket_t * socket, list_t * list, db_t * db, int id);
int server_JSON_addRadioLead(socket_t * socket, list_t * list, http_request_t* request);

void server_HTML_send(socket_t * socket, char * text);
void server_HTML_sendHTMLlist(socket_t * socket, list_t * radioLeads);
void server_HTML_deleteRadioLead(socket_t * client, list_t * list, int id, db_t * self);
void server_HTML_addRadioLead(socket_t * client, list_t * list, char * buf, db_t * db);
void server_HTML_sendTable(socket_t * socket, db_t * self);

void server_addRadioLead(socket_t * client, list_t * list, char * buf, db_t * self);

radio_t * server_getRadioLeadById(int id, db_t * self);
void server_deleteRadioLead(socket_t * client, list_t * list, int id, db_t * self);

int checkData(char * name, char * surname, char * bithdate, char * salary, char * jobExperience, char * programs);

void server_JSON_notFound(socket_t * socket);
void server_JSON_successDeelting(socket_t * socket);
void server_JSON_wrongIndex(socket_t * socket, int id);
void server_JSON_statusOK(socket_t * socket);
void server_JSON_deleteError(socket_t * socket);
void server_JSON_wrongData(socket_t * socket);

void server_HTML_wrongData(socket_t * socket);
void server_HTML_wrongIndex(socket_t * socket);

void server_notFound(socket_t * client);
void server_mainPage(socket_t * socket);


void server_HTML_newRadioLeadTable(socket_t * client);


