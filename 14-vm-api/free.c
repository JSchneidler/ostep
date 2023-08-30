#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int* data = malloc(100 * sizeof(int));
    data[0] = 8;

    printf("%d\n", data[0]);
    free(&data[34]);
    printf("%d\n", data[0]);

    return 0;
}