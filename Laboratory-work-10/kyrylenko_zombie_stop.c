#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Функція-обробник сигналу SIGCHLD */
void sighandler(int sig) {
    wait(0); // Очікуємо завершення (прибираємо зомбі)
}

int main(void) {
    // Реєструємо обробник сигналу: коли дитина помирає, викликається sighandler
    signal(SIGCHLD, &sighandler);

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child of Kyrylenko is finished\n");
        exit(0); // Завершується миттєво
    } else {
        // Parent process
        // Очікування за варіантом: 3 * 8 = 24 секунди
        sleep(24);
        printf("Parent finished.\n");
    }
    return EXIT_SUCCESS;
}
