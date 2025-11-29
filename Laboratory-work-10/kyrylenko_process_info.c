#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    fprintf(stdout, "I am process with pid=%d\n", getpid());
    fprintf(stdout, "My parent pid=%d\n", getppid());
    fprintf(stdout, "My user id=%d\n", getuid());
    fprintf(stdout, "My group id=%d\n", getgid());
    fprintf(stdout, "My group process id=%d\n", getpgrp());
    return 0;
}
