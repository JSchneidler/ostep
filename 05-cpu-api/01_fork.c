#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int x = 5;

    int rc = fork();
    if (rc < 0) {
        // Error
        perror("fork");
    } else if (rc == 0) {
        // Child
        printf("(c) x: %d\n", x);
        x = 10;
        printf("(c) x: %d\n", x);
    } else {
        // Parent
        printf("(p) x: %d\n", x);
        x = 20;
        printf("(p) x: %d\n", x);
    }

    return 0;
}