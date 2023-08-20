#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int fd = open("./shared.txt", O_CREAT|O_TRUNC|O_WRONLY, 0644);

    char* s = "hello\n";

    int rc = fork();
    if (rc < 0) {
        perror("fork");
    } else if (rc == 0) {
        // Child
        write(fd, s, 6);
    } else {
        // Parent
        write(fd, s, 6);
    }

    return 0;
}