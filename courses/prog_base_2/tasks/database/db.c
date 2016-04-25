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

int db_insertRadioLead(db_t * self, radio_t * radio){
	int newRadioLeadId = -1;
	sqlite3_stmt * stmt = NULL;
	int rc = 0;
	if (SQLITE_OK != sqlite3_prepare_v2(self->db, 
		"INSERT INTO RadioLead (Name, Surname, YearOfJobBeginning, Salary, Style, JobExperience, Programs) VALUES (?,?,?,?,?,?,?);", -1, &stmt, NULL)) {
		printf("Not prepared!\n");
	}
	sqlite3_bind_text(stmt, 1, radio->name, strlen(radio->name), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, radio->surname, strlen(radio->surname), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, radio->jobBeginDate, strlen(radio->jobBeginDate), SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 4, radio->salary);
	sqlite3_bind_text(stmt, 5, radio->style, strlen(radio->style), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 6, radio->jobExperience);
	sqlite3_bind_int(stmt, 7, radio->programsAmount);

	if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
		printf("Data isn`t inserted! %d\n", rc);
	}
	newRadioLeadId = (int)sqlite3_last_insert_rowid(self->db);
	sqlite3_finalize(stmt);
	return newRadioLeadId;
}

radio_t * db_getRadioLeadById(db_t * self, int id){
	radio_t * radio = malloc(sizeof(radio_t*));
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, "SELECT * FROM RadioLead WHERE Id = ?;", -1, &stmt, 0);
	sqlite3_bind_int(stmt, 1, id);
	int rc = sqlite3_step(stmt);
	while (1){
		if (SQLITE_ERROR == rc){
			printf("Can't select radio Lead\n");
			exit(EXIT_SUCCESS);
		}
		else if (SQLITE_DONE == rc){
			sqlite3_finalize(stmt);
			return radio;
		}
		else{
			_fillRadioLead(stmt, radio);
		}
	}
	sqlite3_finalize(stmt);
}

void db_updateRadioLead(db_t * self, radio_t * radio, int id){
	sqlite3_stmt * stmt = NULL;
	int rc = 0;
	if (SQLITE_OK != sqlite3_prepare_v2(self->db, 
		"UPDATE RadioLead SET Name = ?,Surname = ?,YearOfJobBeginning = ?,Salary = ?,Style = ?,JobExperience = ?,Programs = ? WHERE Id = ?;", -1, &stmt, NULL)) {
		printf("Not prepared!\n");
	}
	sqlite3_bind_text(stmt, 1, radio->name, strlen(radio->name), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, radio->surname, strlen(radio->surname), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, radio->jobBeginDate, strlen(radio->jobBeginDate), SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 4, radio->salary);
	sqlite3_bind_text(stmt, 5, radio->style, strlen(radio->style), SQLITE_TRANSIENT);
	sqlite3_bind_double(stmt, 6, radio->jobExperience);
	sqlite3_bind_int(stmt, 7, radio->programsAmount);
	sqlite3_bind_int(stmt, 8, id);

	if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
		printf("Data isn`t updated! %d\n", rc);
	}
	sqlite3_finalize(stmt);
}

void db_deleteRadioLead(db_t * self, int id){
	sqlite3_stmt * stmt = NULL;
	if (SQLITE_OK != sqlite3_prepare_v2(self->db, "DELETE FROM RadioLead WHERE Id = ?;", -1, &stmt, 0)){
		printf("Not prepared!\n");
	}
	sqlite3_bind_int(stmt, 1, id);
	int rc = sqlite3_step(stmt);
	if (SQLITE_DONE != rc) {
		printf("Not deleted! %i\n", rc);
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