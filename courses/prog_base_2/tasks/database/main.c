#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "libsqlite3.lib")

#include "db.h"

int main() {
	const char * dbFile = "radio.db";
	radio_t radioList[200];
	db_t * db = db_new(dbFile);

	int count = db_getRadioTask(db, 2, 4001, radioList, 200);
	printf("Amount of filtrated Radio Leads: %d\n\n", count);
	radio_print(&radioList[count - 1]);	
	//db_insertRadioLead(db, &radioList[count - 1]);
	//db_updateRadioLead(db, &radioList[count - 1], 3);
	//db_deleteRadioLead(db,1);
	int amountOfRadioLeads = db_getCountOfRadioLeads(db);
	printf("Amount of all radio Leads: %d\n\n", amountOfRadioLeads);
	radio_t * radio = db_getRadioLeadById(db, 5);
	radio_print(radio);

	db_free(db);
	getchar();
	return 0;
}
