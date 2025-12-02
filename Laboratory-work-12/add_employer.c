#include <stdio.h>
#include "employer.h"

void add_employer(PGconn *conn) {
    PGresult *res;
    
    // 1. Початок транзакції
    res = PQexec(conn, "START TRANSACTION");
    PQclear(res);

    // 2. Блокування
    res = PQexec(conn, "LOCK TABLE employer IN EXCLUSIVE MODE");
    PQclear(res);

    // 3. Вставка даних (Новий запис: ID 3, Shevchenko, 600)
    res = PQexec(conn, "INSERT INTO employer VALUES (3, 'Shevchenko', 600)");
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "INSERT failed: %s", PQerrorMessage(conn));
    } else {
        printf("Data inserted successfully.\n");
    }
    PQclear(res);

    // 4. Завершення
    res = PQexec(conn, "COMMIT");
    PQclear(res);
}

