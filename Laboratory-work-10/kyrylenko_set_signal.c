#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    // Перевірка наявності аргументу (PID)
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Конвертація аргументу в PID
    pid = (pid_t) atoi(argv[1]);

    // Надсилання сигналу SIGUSR2
    if (kill(pid, SIGUSR2) == 0)
        printf("Sent SIGUSR2 to process with PID=%d!\n", pid);
    else {
        perror("Error sending signal");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
