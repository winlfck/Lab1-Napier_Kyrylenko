#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd, bytes;
    char buffer[256];

    if (argc < 2) return EXIT_FAILURE;
    sscanf(argv[1], "%d", &fd);
    memset(buffer, 0, sizeof(buffer));

    bytes = read(fd, buffer, sizeof(buffer));
    printf("I'm child process of Kyrylenko with pid=%d.\n", getpid());
    printf("I read %d bytes: %s\n", bytes, buffer);
    return EXIT_SUCCESS;
}
