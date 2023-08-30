#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int* i = NULL;
    printf("%d\n", *i); // Causes segfault

    return 0;
}