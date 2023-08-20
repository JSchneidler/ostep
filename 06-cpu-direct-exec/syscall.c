#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define ITERS 100000
#define CLOCK CLOCK_PROCESS_CPUTIME_ID

int main(int argc, char* argv[])
{
    struct timespec ts;
    if (clock_getres(CLOCK, &ts) != 0)
        perror("clock_getres");
    printf("Clock res: %ldns\n", ts.tv_nsec);

    long sum = 0;
    long low = 0;
    long high = 0;
    for (int i = 0; i < ITERS; i++) {
        if (clock_gettime(CLOCK, &ts) != 0)
            perror("clock_gettime");
        long a = ts.tv_nsec;

        read(STDOUT_FILENO, NULL, 0);

        if (clock_gettime(CLOCK, &ts) != 0)
            perror("clock_gettime");
        long b = ts.tv_nsec;

        long diff = b-a;
        sum += diff;
        if (diff < low)
            low = diff;
        else if (diff > high)
            high = diff;
    }

    printf("Avg: %ldns\n", sum/ITERS);
    printf("Low: %ldns\n", low);
    printf("High: %ldns\n", high);

    return 0;
}