#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "socket.h"

#define MAX_AMOUNT_OF_SYMBOLS 256

typedef struct {
	char key[MAX_AMOUNT_OF_SYMBOLS];
	char value[MAX_AMOUNT_OF_SYMBOLS];
} keyvalue_t;

typedef struct {
	char method[20];
	char uri[256];
	keyvalue_t * form;
	int formLength;

} http_request_t;

void server_info(socket_t * client);
http_request_t http_request_parse(const char * const request);
