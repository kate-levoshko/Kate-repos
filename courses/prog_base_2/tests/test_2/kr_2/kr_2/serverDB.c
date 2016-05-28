#include "serverDB.h"

void server_db(socket_t * client, http_request_t * req, db_t * db, list_t * radioLead){
	char buffer[10240] = "";

	if (strcmp(req->method, "GET") == 0){
		db_getRadioLead(db, radioLead);

		cJSON * jsonText = cJSON_CreateArray();

		for (int i = 0; i < list_size(radioLead); i++){
			cJSON * radioLead = cJSON_CreateObject();
			cJSON_AddItemToObject(radioLead, "Name", cJSON_CreateString(radio_getName(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "Surname", cJSON_CreateString(radio_getSurname(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "YearOfJobBeginning", cJSON_CreateString(radio_getJobBeginDate(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "Salary", cJSON_CreateNumber(radio_getSalary(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "Style", cJSON_CreateString(radio_getStyle(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "JobExperience", cJSON_CreateNumber(radio_getJobExperience(list_get(radioLead, i))));
			cJSON_AddItemToObject(radioLead, "Programs", cJSON_CreateNumber(radio_getProgramsAmount(list_get(radioLead, i))));
			cJSON_AddItemToArray(jsonText, radioLead);
		}

		char * jsonArray = cJSON_Print(jsonText);

		strcat(buffer, jsonArray);
		free(jsonArray);
	}

	socket_write_string(client, buffer);
	socket_close(client);
}

void server_notFound(socket_t * client)
{
    char buffer[1024] = "";
    char * pageText = "404 Page Not Found!";

    sprintf(buffer,
            "HTTP/1.1 404 Not Found\n"
            "Content-Type: text/html\n"
            "Content-Length: %zu\n"
            "\n%s", strlen(pageText), pageText);

    socket_write_string(client, buffer);
    socket_close(client);
}
