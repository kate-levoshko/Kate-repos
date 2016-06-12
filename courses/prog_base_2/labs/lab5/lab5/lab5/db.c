
#include "db.h"



db_t * db_new(const char * dbFile){
	db_t * self = malloc(sizeof(struct db_s));
	int rc = sqlite3_open(dbFile, &self->db);
	if (SQLITE_ERROR == rc){
		puts("Can't open database");
		exit(1);
	}
	return self;
}

void db_free(db_t * self) {
	sqlite3_close(self->db);
	free(self);
}

void db_parse(db_t * self, list_t * rl_list){
	const char * sqlQuery = "SELECT * FROM RadioLead;";

	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);

	while (1){
		int rc = sqlite3_step(stmt);
		if (SQLITE_ERROR == rc){
			puts("Can't select!");
			exit(1);
		}
		else if (SQLITE_DONE == rc){
			break;
		}
		else if (SQLITE_ROW == rc){
			int id = sqlite3_column_int(stmt, 0);
			char * name = (char *)sqlite3_column_text(stmt, 1);
			char * surname = (char *)sqlite3_column_text(stmt, 2);
			char * birthdate = (char *)sqlite3_column_text(stmt, 3);
			int salary = sqlite3_column_int(stmt, 4);
			double jobExp = sqlite3_column_double(stmt, 5);
			int programs = sqlite3_column_int(stmt, 6);

			radio_t * r = radio_newRadioLead();
			radio_setLeadInfo(r, id, name, surname, birthdate, salary, jobExp, programs);
			list_push_back(rl_list, r);
		}
	}

	sqlite3_finalize(stmt);
}

radio_t * db_getRadioLeadById(db_t * self, int id){
	const char * sqlQuery = "SELECT * FROM RadioLead WHERE Id = ?";
	radio_t * rl = NULL;
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);

	int rc = sqlite3_step(stmt);
	if (rc == SQLITE_ERROR){
		printf("Can't select!\n");
		return NULL;
	}
	else if (rc == SQLITE_ROW){
		int id = sqlite3_column_int(stmt, 0);
		char * name = (char *)sqlite3_column_text(stmt, 1);
		char * surname = (char *)sqlite3_column_text(stmt, 2);
		char * birthdate = (char *)sqlite3_column_text(stmt, 3);
		int salary = sqlite3_column_int(stmt, 4);
		double jobExperience = sqlite3_column_double(stmt, 5);
		int programs = sqlite3_column_int(stmt, 6);

		rl = radio_newRadioLead();
		radio_setLeadInfo(rl, id, name, surname, birthdate, salary, jobExperience, programs);
	}
	sqlite3_finalize(stmt);
	return rl;
}

int db_deleteRadioLeadById(db_t * self, list_t * list, int id){
	const char * sqlQuery = "DELETE FROM RadioLead WHERE Id = @id;";

	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);

	int rc = sqlite3_step(stmt);
	if (SQLITE_ERROR == rc){
		return 0;
	}
	list_free(list);
	list = list_new();
	db_parse(self, list);
	sqlite3_finalize(stmt);
	return 1;
}

int db_addRadioLead(db_t * self, list_t * list, char * buf){
	const char * sqlQuery = "INSERT INTO RadioLead (Name,Surname,Birthdate,Salary,JobExperience,Programs) VALUES (@name,@surname,@birthdate,@salary,@jobExperience,@programs);";
	int last = -1;
	int rc;
	sqlite3_stmt * stmt = NULL;
	rc = sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);
	printf("\nReturn cod: %i\n", rc);
	http_request_t req = http_request_parse(buf);
	char * name = (char *)http_request_getArg(&req, "name");
	char * surname = (char *)http_request_getArg(&req, "surname");
	char * birthdate = (char *)http_request_getArg(&req, "birthdate");
	char * salary = (char *)http_request_getArg(&req, "salary");
	char * jobExp = (char *)http_request_getArg(&req, "jobExperience");
	char * programs = (char *)http_request_getArg(&req, "programs");

	rc = sqlite3_bind_text(stmt, 1, name, strlen(name), NULL);
	printf("\nReturn cod: %i\n", rc);
	sqlite3_bind_text(stmt, 2, surname, strlen(surname), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, birthdate, strlen(birthdate), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, salary, strlen(salary), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 5, jobExp, strlen(jobExp), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 6, programs, strlen(programs), SQLITE_TRANSIENT);

	rc = sqlite3_step(stmt);
	if (SQLITE_ERROR == rc){
		return 0;
	}
	else if (SQLITE_MISMATCH == rc){
		return -1;
	}

	last = (int)sqlite3_last_insert_rowid(self->db);
	sqlite3_finalize(stmt);
	return last;
}

cJSON * db_task1(db_t * self, char * buf){
	cJSON * arr = cJSON_CreateArray();
	const char * sqlQuery = "SELECT * FROM RadioLead WHERE Programs > ? AND Salary > ?;";
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);

	http_request_t req = http_get_request_parse(buf);
	char * programs = (char *)http_request_getArg(&req, "programs");
	char * salary = (char *)http_request_getArg(&req, "salary");
	sqlite3_bind_text(stmt, 1, programs, strlen(programs), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, salary, strlen(salary), SQLITE_TRANSIENT);

	while (1){
		int rc = sqlite3_step(stmt);
		if (SQLITE_ERROR == rc){
			puts("Can't select!");
			exit(1);
		}
		else if (SQLITE_DONE == rc){
			break;
		}
		else if (SQLITE_ROW == rc){
			int id = sqlite3_column_int(stmt, 0);
			char * name = (char *)sqlite3_column_text(stmt, 1);
			char * surname = (char *)sqlite3_column_text(stmt, 2);
			char * birthdate = (char *)sqlite3_column_text(stmt, 3);
			int salary = sqlite3_column_int(stmt, 4);
			double jobExp = sqlite3_column_double(stmt, 5);
			int programs = sqlite3_column_int(stmt, 6);

			radio_t * r = radio_newRadioLead();
			radio_setLeadInfo(r, id, name, surname, birthdate, salary, jobExp, programs);
			
			cJSON_AddItemToArray(arr, radio_JSON_radioLeadToJson(r));
		}
	}
	sqlite3_finalize(stmt);
	return arr;
}

cJSON * db_task2(db_t * self, char * buf){
	cJSON * arr = cJSON_CreateArray();
	const char * sqlQuery = "SELECT * FROM RadioLead WHERE Programs < ? AND Salary < ? ; ";
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, NULL);

	http_request_t req = http_request_parse(buf);
	char * programs = (char *)http_request_getArg(&req, "programs");
	char * salary = (char *)http_request_getArg(&req, "salary");
	sqlite3_bind_text(stmt, 1, programs, strlen(programs), SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 2, salary, strlen(salary), SQLITE_TRANSIENT);

	while (1){
		int rc = sqlite3_step(stmt);
		if (SQLITE_ERROR == rc){
			puts("Can't select!");
			exit(1);
		}
		else if (SQLITE_DONE == rc){
			break;
		}
		else if (SQLITE_ROW == rc){
			int id = sqlite3_column_int(stmt, 0);
			char * name = (char *)sqlite3_column_text(stmt, 1);
			char * surname = (char *)sqlite3_column_text(stmt, 2);
			char * birthdate = (char *)sqlite3_column_text(stmt, 3);
			int salary = sqlite3_column_int(stmt, 4);
			double jobExp = sqlite3_column_double(stmt, 5);
			int programs = sqlite3_column_int(stmt, 6);

			radio_t * r = radio_newRadioLead();
			radio_setLeadInfo(r, id, name, surname, birthdate, salary, jobExp, programs);

			cJSON_AddItemToArray(arr, radio_JSON_radioLeadToJson(r));
		}
	}
	sqlite3_finalize(stmt);
	return arr;
}

int db_getNewId(db_t* db){
	const char * sqlQuery = "SELECT seq FROM sqlite_sequence WHERE name = \"RadioLead\"";
	int res = 0;
	sqlite3_stmt * stmt = NULL;
	sqlite3_prepare_v2(db, sqlQuery, strlen(sqlQuery), &stmt, NULL);


	int rc = sqlite3_step(stmt);
	if (SQLITE_ERROR == rc){
		puts("Can't select!");
		return -1;
	}
	else if (SQLITE_ROW == rc){
		res = sqlite3_column_int(stmt, 0);
	}
	return res;
}
