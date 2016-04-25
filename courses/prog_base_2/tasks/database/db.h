#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sqlite3.h"
#include "radio.h"

typedef struct db_s db_t;

db_t * db_new(const char * dbFile); // constructor
void db_free(db_t * self); //dectructor

// CRUD 

radio_t * db_getRadioLeadById(db_t * self, int id);
int db_insertRadioLead(db_t * self, radio_t * radio);
void db_updateRadioLead(db_t * self, radio_t * radio, int id);
void db_deleteRadioLead(db_t * self, int id);
	
static void _fillRadioLead(sqlite3_stmt * stmt, radio_t * radio);
	
int db_getCountOfRadioLeads(db_t * self);
int db_getRadioTask(db_t * self, int P, int K, radio_t * arr, int arrMax);
	