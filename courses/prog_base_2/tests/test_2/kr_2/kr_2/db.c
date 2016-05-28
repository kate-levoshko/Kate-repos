#include "db.h"

struct db_s {
	sqlite3 * db;
};

db_t * db_new(const char * dbFile) {
	db_t * self = malloc(sizeof(struct db_s));
	int rc = sqlite3_open(dbFile, &self->db);
	if (SQLITE_ERROR == rc) {
		printf("Can't open database\n");
		exit(EXIT_SUCCESS);
	}
	return self;
}

void db_free(db_t * self) {
	sqlite3_close(self->db);
	free(self);
}


radio_t * db_getRadioLead(db_t * self, int id){
	list_t * list = list_new();
	radio_t * radio = malloc(sizeof(radio_t*));
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, "SELECT * FROM RadioLead ;", -1, &stmt, 0);
	sqlite3_bind_int(stmt, 1, id);
	int rc = sqlite3_step(stmt);
	while (1){
		if (SQLITE_ERROR == rc){
			printf("Can't select radio Lead\n");
			exit(EXIT_SUCCESS);
		}
		else if (SQLITE_DONE == rc){
			break;
		}
		else if (SQLITE_ROW == rc){
			list_add(list, SQLITE_ROW);
		}
	}
	sqlite3_finalize(stmt);
}


static void _fillRadioLead(sqlite3_stmt * stmt, radio_t * radio) {
	int id = sqlite3_column_int(stmt, 0);
	const unsigned char * name = sqlite3_column_text(stmt, 1);
	const unsigned char * surname = sqlite3_column_text(stmt, 2);
	const unsigned char * yearOfJobBeginning = sqlite3_column_text(stmt, 3);
	int salary = sqlite3_column_int(stmt, 4);
	const unsigned char * style = sqlite3_column_text(stmt, 5);
	double jobExperience = sqlite3_column_double(stmt, 6);
	int programsAmount = sqlite3_column_int(stmt, 7);

	radio->id = id;
	strcpy(radio->name, (const char *)name);
	strcpy(radio->surname, (const char *)surname);
	strcpy(radio->jobBeginDate, (const char *)yearOfJobBeginning);
	radio->salary = salary;
	strcpy(radio->style, (const char *)style);
	radio->jobExperience = jobExperience;
	radio->programsAmount = programsAmount;
}

int db_getCountOfRadioLeads(db_t * self){
	int rc;
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM RadioLead;", -1, &stmt, 0);
	rc = sqlite3_step(stmt);
	if (SQLITE_ERROR == rc) {
		printf("Can't select count\n");
		exit(EXIT_SUCCESS);
	}
	int count = sqlite3_column_int(stmt, 0);
	sqlite3_finalize(stmt);
	return count;
}

int db_getRadioTask(db_t * self, int P, int K, radio_t * arr, int arrMax) {
	sqlite3_stmt * stmt = NULL;
	const char * sqlQuery = "SELECT * FROM RadioLead WHERE Programs > ? AND Salary < ?;";
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
	sqlite3_bind_int(stmt, 1, P);
	sqlite3_bind_int(stmt, 2, K);
	int count = 0;
	while (1) {
		int rc = sqlite3_step(stmt);
		if (SQLITE_ERROR == rc) {
			printf("Can't select radio Leads\n");
			exit(EXIT_SUCCESS);
		}
		else if (SQLITE_DONE == rc) {
			break;
		}
		else {
			_fillRadioLead(stmt, &arr[count]);
			count++;
		}
	}
	sqlite3_finalize(stmt);
	return count;
}