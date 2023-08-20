#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int p[2];
    if (pipe(p) != 0)
        perror("pipe");

    for (int i = 0; i < 2; i++) {
        int rc = fork();
        if (rc < 0) {
            perror("fork");
        } else if (rc == 0) {
            // Child
            printf("(%d) %d\n", getppid(), getpid());
            char pid_s[1024];
            sprintf(pid_s, "%d", getpid());
            write(p[1], pid_s, strlen(pid_s));
            break;
        } else {
            // Parent
            wait(NULL);

            char c[1024];
            read(p[0], c, 5);
            printf("From child: %s\n", c);
        }
    }

    return 0;
}