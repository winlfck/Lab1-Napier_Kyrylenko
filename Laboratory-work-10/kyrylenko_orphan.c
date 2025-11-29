#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        // Цикл: 2 * 8 + 1 = 17 разів
        for (int i = 0; i < 17; i++) {
            printf("Parent of Kyrylenko. My PPID=%d\n", getppid());
            sleep(1);
        }
    } else if (pid > 0) {
        // Parent process
        // Очікування: 8 + 1 = 9 секунд
        sleep(9);
        printf("Parent (PID=%d) is finishing...\n", getpid());
        exit(0); // Батько помирає
    }

    return 0;
}
