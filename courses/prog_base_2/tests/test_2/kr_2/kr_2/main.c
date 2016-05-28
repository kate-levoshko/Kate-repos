#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "socket.h"
#include "sqlite3.h"
#include "sqlite3ext.h"
#include "server.h"

#include <jansson.h>
#include "CURL\include\curl\curl.h"

#include <winsock2.h>
#include <windows.h>



int server_sendJson(socket_t * socket, json_t * root){
	char buffer[5000];
	char * jsonOutput = json_dumps(root, JSON_INDENT(3));
	sprintf(buffer,
		"HTTP/1.1 200 OK\n"
		"Content-Type: application/json\n"
		"Content-Length: %d\n"
		"%s", strlen(jsonOutput), jsonOutput);
	socket_write_string(socket, buffer);
	return 1;
}

void server_info(socket_t* clientSocket)
{
	json_t * student = json_object();
	
	json_object_set_new(student, "student", "Kate Levoshko");
	json_object_set_new(student, "group", "KP-52");
	json_object_set_new(student, "variant", 31);
	char * jsonSM = json_print(student);
	server_sent(clientSocket, jsonSM);
}

/*
size_t write_to_string(void *ptr, size_t size, size_t count, void *stream) {
	strcpy((char*)stream, (char*)ptr);
	return size*count;
}

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

