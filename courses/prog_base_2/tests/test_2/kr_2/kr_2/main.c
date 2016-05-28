#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sqlite3.h"
#include "sqlite3ext.h"

#include "serverDB.h"

#include <jansson.h>
#include "CURL\include\curl\curl.h"

#include <winsock2.h>
#include <windows.h>

// task1
/*
int main()
{
	lib_init();
	socket_t * server = socket_new();
	socket_bind(server, 5000);
	socket_listen(server);
	char buf[10000];
	socket_t * client = NULL;
	while (1)
	{
		client = socket_accept(server);
		socket_read(client, buf, sizeof(buf));
		printf("%s", buf);
		if (strlen(buf) != 0){
			http_request_t rs;
			rs = http_request_parse(buf);
			if (strcmp(rs.method, "GET") == 0 && strcmp(rs.uri, "/info") == 0)
			{
				server_info(client);
			}

		}
	}
	return 0;
}
*/

int main(void){
	lib_init();
	socket_t * server = socket_new();
	socket_bind(server, 5000);
	socket_listen(server);

	char buffer[10240];
	socket_t * client = NULL;

	const char * dbFile = "radio.db";
	db_t * db = db_new(dbFile);

	list_t * radioLead = list_new();

	while (1)
	{
		client = socket_accept(server);
		socket_read(client, buffer, sizeof(buffer));

		if (strlen(buffer) != 0){
			printf(">> Got request:\n%s\n", buffer);
			http_request_t request = http_request_parse(buffer);

			if (strcmp(request.uri, "/info") == 0)
			{
				server_info(client, &request);
			}
			else if (strcmp(request.uri, "/database") == 0)
			{
				server_db(client, &request, db, radioLead);
			}
			else if (strncmp(request.uri, "/files/", 7) == 0)
			{

			}
			else
			{
				server_notFound(client);
			}
		}
	}

	socket_free(client);
	socket_free(server);
	list_free(radioLead);
	db_free(db);
	lib_free();
	getchar();
	return 0;
}
