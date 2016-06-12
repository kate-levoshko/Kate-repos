
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "sqlite3.h"
#include "radio.h"

struct db_s {
	sqlite3 * db;
};

typedef struct db_s db_t;

#include "db.h"

db_t * db_new(const char * dbFile);
void db_free(db_t * self);
void db_parse(db_t * self, list_t * rl_list);
radio_t * db_getRadioLeadById(db_t * self, int id);
int db_deleteRadioLeadById(db_t * self, list_t * radioLead, int id);
int db_addRadioLead(db_t * self, list_t * list, char * buf);
cJSON * db_task1(db_t * self, char * buf);
cJSON * db_task2(db_t * self, char * buf);
int db_getNewId(db_t* db);