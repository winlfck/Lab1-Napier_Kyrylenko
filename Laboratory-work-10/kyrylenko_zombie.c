#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("I am Zombie-process of Kyrylenko\n");
        // Негайно завершується, стаючи зомбі, бо батько спить
        exit(0);
    } else {
        // Parent process
        // Спить, не викликаючи wait()
        sleep(60); 
    }
    return EXIT_SUCCESS;
}
