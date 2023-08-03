This program, `process-run.py`, allows you to see how process states change as programs run and either use the CPU (e.g., perform an add instruction) or do I/O (e.g., send a request to a disk and wait for it to complete). See the README for details.

1. Run process-run.py with the following ﬂags: `-l 5:100,5:100`. What should the CPU utilization be (e.g., the percent of time the CPU is in use?) Why do you know this?

    100% utilization, there is no I/O or other blocking instructions.

2. Now run with these ﬂags: `-l 4:100,1:0`. These ﬂags specify one process with 4 instructions (all to use the CPU), and one that simply issues an I/O and waits for it to be done. How long does it take to complete both processes?

    4 cycles for the first process, 7 for the second process (1 cycle for I/O request, 5 waiting for I/O, and 1 more for the I/O response) for a total of 11 cycles.

3. Switch the order of the processes: `-l 1:0,4:100`. What happens now? Does switching the order matter? Why?

    7 cycles total because the second process can complete all 4 of it's instructions while the first waits for an I/O response. Switching the order mattered in this case because it allowed the I/O process to initiate it's request before the 2nd process started, maximizing usage of the CPU.

4. What happens when you run the following two processes `-l 1:0,4:100 -c -S SWITCH_ON_END`, one doing I/O and the other doing CPU work?

    The 2nd process can no longer run while the 1st waits for I/O to complete, bringing the runtime back up to 11 cycles.

5. Now, run the same processes, but with the switching behavior set to switch to another process whenever one is WAITING for I/O `-l 1:0,4:100 -c -S SWITCH_ON_IO`. What happens now?

    This is the default behavior, performing identically to Question 3 (7 cycles).

6. What happens when you run this combination of processes? `-l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -cp` Are system resources being effectively utilized?

    No. The first and second processes effectively utilize the CPU. The remaining processes (3 and 4) don't as they are scheduled before the first process is allowed to initiate anymore I/O requests, meaning it has to wait until the proccesses are done before initiating (and waiting for) 2 more I/O requests.

7. Now run the same processes, but with `-I IO_RUN_IMMEDIATE` set, which immediately runs the process that issued the I/O. How does this behavior differ? Why might running a process that just completed an I/O again be a good idea?

    This brings the efficiency to 100%. It allows the first process to initiate I/O requests and then perform other work while waiting for the I/O response. When another process completes, the first process is allowed to initiate another I/O request instead of waiting for all other processes to finish. This is a good idea because a process that performs I/O requests will probably do so multiple times, so allowing it to initiate I/O requests and then switch to another process allows more work to be done in less time, increasing CPU utilization.

8. Now run with some randomly generated processes: `-s 1 -l 3:50,3:50` or `-s 2 -l 3:50,3:50` or `-s 3 -l 3:50,3:50`. See if you can predict how the trace will turn out. What happens when you use the ﬂag `-I IO_RUN_IMMEDIATE` vs. `-I IO_RUN_LATER`? What happens when you use `-S SWITCH_ON_IO` vs. `-S SWITCH_ON_END`?

    `IO_RUN_IMMEDIATE` will result in increased CPU utilization as it will prioritize scheduling processes that are initiating I/O requests. This defers all CPU work until no I/O requests are left to initiate, allowing CPU work to complete while waiting for I/O requests to complete. If `IO_RUN_LATER` was used, all the I/O requests would be deferred until CPU work is completed, which would waste the CPU as it could've performed this work while waiting for the I/O response.  
    `SWITCH_ON_IO` will result in increased CPU utilization as it will switch to another process if an I/O request is performed, instead of waiting for I/O to complete (and wasting cycles) as in `SWITCH_ON_END`.