#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int mem_mb = atoi(argv[1]);
    printf("%d: %dMb\n", getpid(), mem_mb);

    int size = mem_mb * 1024 * 1024;
    int* array = (int*) calloc(size/sizeof(int), sizeof(int));

    for(int i = 0; i < size / sizeof(int); i++)
        array[i] = -1;

    for(;;){}

    return 0;
}