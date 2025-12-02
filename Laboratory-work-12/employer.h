#ifndef EMPLOYER_H
#define EMPLOYER_H
#include <libpq-fe.h>

// Оголошення функцій
PGconn* connect_employer(void);
void add_employer(PGconn *conn);
void get_employer(PGconn *conn);

#endif
