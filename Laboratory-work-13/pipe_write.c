#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int file_pipes[2];
    const char message[] = "The Laboratory Work of Kyrylenko";
    char fd_str[10];
    
    if (pipe(file_pipes) == 0) {
        if (fork() == 0) {
            close(file_pipes[1]); 
            sprintf(fd_str, "%d", file_pipes[0]);
            execl("./pipe_read", "pipe_read", fd_str, NULL);
        } else {
            close(file_pipes[0]);
            printf("I'm parent process of Kyrylenko with pid=%d.\n", getpid());
            int bytes = write(file_pipes[1], message, strlen(message)); // Без +1 для чистоти
            printf("I wrote %d bytes.\n", bytes);
            wait(NULL);
        }
    }
    return EXIT_SUCCESS;
}
