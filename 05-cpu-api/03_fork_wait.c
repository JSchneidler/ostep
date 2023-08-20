#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0) {
        perror("fork");
    } else if (rc == 0) {
        // Child
        printf("Hello\n");
    } else {
        // Parent
        sleep(3);
        printf("Goodbye\n");
    }

    return 0;
}