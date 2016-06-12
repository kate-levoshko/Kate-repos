#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stddef.h>  // ptrdiff_t
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct {
	char key[256];
	char value[256];
} keyvalue_t;

typedef struct {
	char method[8];
	char uri[256];
	keyvalue_t * form;
	int formLength;
} http_request_t;

http_request_t 
http_request_parse(const char * const request);

http_request_t
http_get_request_parse(const char * const request);

const char *
http_request_getArg(http_request_t * self, const char * key);

const char *
keyvalue_toString(keyvalue_t * self);
