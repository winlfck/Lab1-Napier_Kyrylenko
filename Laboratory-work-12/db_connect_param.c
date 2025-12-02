#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>

int main(int argc, char *argv[]) {
    PGconn *conn;

    // Перевірка кількості аргументів (Назва програми + 5 параметрів)
    if (argc != 6) {
        fprintf(stderr, "Usage: %s host port database user password\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Отримуємо значення з аргументів командного рядка
    char *db_host = argv[1];
    char *db_port = argv[2];
    char *db_name = argv[3];
    char *user_name = argv[4];
    char *password = argv[5];

    // Встановлення з'єднання (використовуємо PQsetdbLogin, як на Рис. 8b)
    // Параметри: host, port, options, tty, dbname, login, pwd
    conn = PQsetdbLogin(db_host, db_port, NULL, NULL, db_name, user_name, password);

    // Перевірка статусу з'єднання
    if (PQstatus(conn) == CONNECTION_OK) {
        printf("Connection to database %s is successfull!\n", db_name);
        PQfinish(conn); // Закриття з'єднання
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Connect to database %s failed: %s", db_name, PQerrorMessage(conn));
        PQfinish(conn);
        return EXIT_FAILURE;
    }
}
