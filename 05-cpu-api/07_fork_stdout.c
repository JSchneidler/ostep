#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0) {
        perror("fork");
    } else if (rc == 0) {
        // Child
        close(STDOUT_FILENO);
        printf("Hello from child\n");
    } else {
        // Parent
    }

    return 0;
}