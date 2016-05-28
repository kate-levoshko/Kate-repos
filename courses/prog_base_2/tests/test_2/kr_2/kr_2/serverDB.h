#include "socket.h"
#include "server.h"
#include "db.h"
#include "cJSON.h"

void server_db(socket_t * client, http_request_t * req, db_t * db, list_t * radioLead);
void server_notFound(socket_t * client);