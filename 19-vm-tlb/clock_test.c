#include <mach/mach_time.h>

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define CLOCK CLOCK_UPTIME_RAW

void test_clock(char clock[], clockid_t clock_id)
{
    printf("%s:\n", clock);

    struct timespec res;
    clock_getres(clock_id, &res);
    printf("    res: %luns\n", res.tv_nsec);

    struct timespec time;
    clock_gettime(clock_id, &time);
    printf("    clock_gettime: %lu.%lu\n", time.tv_sec, time.tv_nsec);

    uint64_t time_nsec;
    time_nsec = clock_gettime_nsec_np(clock_id);
    printf("    clock_gettime_nsec_np: %llu\n", time_nsec);
}

int main(int argc, char* argv[])
{
    test_clock("CLOCK_MONOTONIC_RAW", CLOCK_MONOTONIC_RAW);
    test_clock("CLOCK_UPTIME_RAW", CLOCK_UPTIME_RAW);
    test_clock("CLOCK_PROCESS_CPUTIME_ID", CLOCK_PROCESS_CPUTIME_ID);

    uint64_t mach_time;
    mach_time = mach_absolute_time();
    printf("mach_absolute_time: %llu\n", mach_time);

    return 0;
}