#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define CLOCK CLOCK_PROCESS_CPUTIME_ID

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || argv[2] == NULL)
    {
        printf("Missing args\n");
        exit(EXIT_FAILURE);
    }

    int num_pages = atoi(argv[1]);
    int iterations = atoi(argv[2]);
    printf("%d pages, %d iterations\n", num_pages, iterations);

    long page_size = sysconf(_SC_PAGESIZE);
    long jump = page_size / sizeof(int);

    int *array = calloc(num_pages, page_size);

    printf("Jump: %ld\n", jump);
    printf("calloc: %ld\n", num_pages * page_size);
    printf("jump * pages: %ld\n", jump * num_pages);
    printf("jump * pages * sizeof(int): %ld\n", jump * num_pages * sizeof(int));

    uint64_t start_ns = clock_gettime_nsec_np(CLOCK);
    for (int i = 0; i < iterations; i++)
        for (int j = 0; j < (jump * num_pages); j += jump)
            array[j] += 1;
    uint64_t end_ns = clock_gettime_nsec_np(CLOCK);

    free(array);

    struct timespec res;
    clock_getres(CLOCK, &res);

    printf("Avg: %lluns\n", (end_ns - start_ns) / (iterations * num_pages));
    printf("Page Size: %ld\n", page_size);
    printf("Res: %ldns\n", res.tv_nsec);

    return 0;
}