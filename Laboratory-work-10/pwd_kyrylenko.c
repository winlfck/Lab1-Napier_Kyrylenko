#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    // Аргументи для команди pwd -L -P
    // Останній елемент має бути NULL
    char *args[] = {"pwd", "-L", "-P", NULL};

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("The child of Kyrylenko executes: pwd\n");
        // Заміна образу процесу на команду pwd
        execvp("pwd", args); // Використовуємо execvp для пошуку в PATH
        
        // Якщо execvp повернеться, значить сталася помилка
        perror("execvp error");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        // Parent process
        sleep(1); // Затримка, щоб child встиг вивести повідомлення
        wait(NULL); // Чекаємо завершення child
    } else {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
