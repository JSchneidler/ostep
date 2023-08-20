1. Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to some-
thing (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?

    The parent and child do not share memory, so their instance of `x` is unique.

2. Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?

    Yes, multiple processes can access the same file. They can both write to the file at the same time and it doesn't seem to corrupt data, but it's probably not advised. On my system the write syscall seems to be atomic.

4. Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?

    To support multiple ways of executing programs, and maybe legacy support.

5. Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?

    Wait returns the PID of the terminated child, or -1 on error. Using wait in the child returns -1 as the child has no children.

6. Write a slight modification of the previous program, this time us-
ing waitpid() instead of wait(). When would waitpid() be
useful?

    waitpid would be preferable if you wanted to wait for a certain child process to terminate or change state instead of just any child.

7. Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?

    The output is not printed.