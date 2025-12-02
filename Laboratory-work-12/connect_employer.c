#include <stdio.h>
#include <stdlib.h>
#include "employer.h"

PGconn* connect_employer(void) {
    PGconn *conn;
    // Параметри підключення
    const char *conninfo = "host=localhost port=5432 dbname=ai245-kyrylenko_db user=ai245-kyrylenko password=qwerty1234";

    conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection failed: %s\n", PQerrorMessage(conn));
        return NULL;
    }

    printf("Connected to database successfully!\n");
    return conn;
}
