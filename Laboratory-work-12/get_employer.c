#include <stdio.h>
#include "employer.h"

void get_employer(PGconn *conn) {
    PGresult *res;

    res = PQexec(conn, "START TRANSACTION");
    PQclear(res);

    // Вибірка даних
    res = PQexec(conn, "SELECT * FROM employer");
    
    if (PQresultStatus(res) == PGRES_TUPLES_OK) {
        printf("\n--- Employer Table ---\n");
        printf("%-5s %-15s %-10s\n", "ID", "Name", "Salary");
        
        int rows = PQntuples(res);
        int i; // Оголошення змінної ПЕРЕД циклом
for (i = 0; i < rows; i++) {
            printf("%-5s %-15s %-10s\n", 
                PQgetvalue(res, i, 0), 
                PQgetvalue(res, i, 1), 
                PQgetvalue(res, i, 2));
        }
    } else {
        fprintf(stderr, "SELECT failed: %s", PQerrorMessage(conn));
    }
    PQclear(res);

    res = PQexec(conn, "COMMIT");
    PQclear(res);
}
