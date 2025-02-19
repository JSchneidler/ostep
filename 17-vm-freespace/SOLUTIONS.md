1. First run with the flags `-n 10 -H 0 -p BEST -s 0` to generate a few random allocations and frees. Can you predict what alloc()/free() will return? Can you guess the state of the free list after each request? What do you notice about the free list over time?

    The free list becomes more fragmented over time as no coalescing is done.

2. How are the results different when using a WORST fit policy to search the free list (-p WORST)? What changes?

    The free list is more fragmented with worst fit.

3. What about when using FIRST fit (-p FIRST)? What speeds up when you use first fit?

    Search speed increases due to a smaller search space.

5. Coalescing of a free list can be quite important. Increase the number of random allocations (say to -n 1000). What happens to larger allocation requests over time? Run with and without coalescing (i.e., without and with the -C flag). What differences in outcome do you see? How big is the free list over time in each case? Does the ordering of the list matter in this case?

    Larger allocation requests have a lower chance of successfully being served as the free list grows. With coalescence, the free list remains smaller throughout the program and allocation requests are more likely to succeed due to less fragmentation. The order of the list does matter, ADDRSORT seems to be the most compatible with coalescence.

6. What happens when you change the percent allocated fraction -P to higher than 50? What happens to allocations as it nears 100? What about as the percent nears 0?

    Higher than 50% results in more allocations than frees, resulting in an increase of allocation failures as time goes on. Less than 50% results in more frees than allocations, allowing more allocations to succeed indefinitely.