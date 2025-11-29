#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* Функція-оброблювач сигналу SIGUSR2 */
static void sig_usr(int signo) {
    if (signo == SIGUSR2)
        printf("Process of Kyrylenko got signal SIGUSR2\n");
}

int main(void) {
    // Реєстрація обробника сигналу
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        fprintf(stderr, "Error catching SIGUSR2\n");
        return EXIT_FAILURE;
    }

    printf("My PID = %d. Waiting for SIGUSR2...\n", getpid());

    /* Безкінечний цикл очікування */
    for (;;)
        pause(); // Призупиняє процес, поки не надійде сигнал

    return EXIT_SUCCESS;
}
