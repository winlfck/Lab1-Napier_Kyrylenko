#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main() {
    PGconn *conn;
    // Параметри з ЛР №11
    const char *conninfo = "host=localhost port=5432 dbname=ai245-kyrylenko_db user=ai245-kyrylenko password=qwerty1234";

    conn = PQconnectdb(conninfo);

    if (PQstatus(conn) != CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        return EXIT_FAILURE;
    }

    printf("Connection to database ai245-kyrylenko_db is successful!\n");
    PQfinish(conn);
    return EXIT_SUCCESS;
}
