#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *print_message(void *ptr) {
    char *message = (char *)ptr;
    for (int i = 1; i <= 13; i++) {
        printf("%s: %d\n", message, i);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    const char *msg1 = "Thread 1 (Kyrylenko)";
    const char *msg2 = "Thread 2 (Kyrylenko)";

    pthread_create(&thread1, NULL, print_message, (void*)msg1);
    pthread_create(&thread2, NULL, print_message, (void*)msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
