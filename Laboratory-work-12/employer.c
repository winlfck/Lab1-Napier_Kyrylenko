#include "employer.h"
#include <stdlib.h>

int main() {
    PGconn *conn = connect_employer();
    if (conn == NULL) return EXIT_FAILURE;

    // Виклик функцій з інших модулів
    add_employer(conn);
    get_employer(conn);

    PQfinish(conn);
    return EXIT_SUCCESS;
}
