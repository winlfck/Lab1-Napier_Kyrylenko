#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key = 1508;
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    strcpy(message.msg_text, "Message from Kyrylenko");
    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Sent: %s\n", message.msg_text);
    return 0;
}
