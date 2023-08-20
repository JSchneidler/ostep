#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    for (int i = 0; i < 7; i++) {
        fflush(stdout);
        int rc = fork();
        if (rc < 0) {
            perror("fork");
            exit(1);
        } else if (rc > 0) {
            // Parent
            wait(NULL);
        } else {
            // Child
            switch (i) {
                case 0:
                    printf("(%d) execl:\n", getpid());
                    execl("/bin/ls", "/bin/ls", ".", NULL);
                case 1:
                    printf("(%d), execlp:\n", getpid());
                    execlp("ls", "ls", ".", NULL);
                case 2:
                    printf("(%d), execle:\n", getpid());
                    char* l_env[] = {"ENV1=Hello, ", "ENV2=World!", NULL};
                    execle("/bin/bash", "/bin/bash", "-c", "echo $ENV1 $ENV2", NULL, l_env);
                case 3:
                    printf("(%d), execv:\n", getpid());
                    char* v_args[] = {"/bin/ls", ".", NULL};
                    execv("/bin/ls", v_args); //
                case 4:
                    printf("(%d), execvp:\n", getpid());
                    char* vp_args[] = {"ls", ".", NULL};
                    execvp("ls", vp_args);
                case 5:
                    printf("(%d), execve:\n", getpid());
                    char* v_env[] = {"ENV=World!", NULL};
                    char* ve_args[] = {"/usr/bin/bash", "-c", "echo Hello, $ENV", NULL};
                    execve("/bin/bash", ve_args, v_env);
                case 6:
                    wait(NULL);
                    perror("wait");
                    break;
            }
        }
    }

    return 0;
}