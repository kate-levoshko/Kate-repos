#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "socket.h"
#include "sqlite3.h"
#include "sqlite3ext.h"
#include "server.h"
#include "cJSON.h"

#include <jansson.h>
#include "CURL\include\curl\curl.h"

#include <winsock2.h>
#include <windows.h>

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
/*

int main(void){
	json_t* test = json_pack("{s:s}", "KATYA", "SDAST");
	puts(json_dumps(test, JSON_INDENT(3)));

	CURL *curl;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();

	getchar();
}
*/

