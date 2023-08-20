1. Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

    FIFO and SJF:  
    Response time: (0 + 200 + 400) / 3 = **200**  
    Turnaround time: (200 + 400 + 600) / 3 = **400**

2. Now do the same but with jobs of different lengths: 100, 200, and 300.

    FIFO and SJF:  
    Response time: (0 + 100 + 300) / 3 = **~133.33**  
    Turnaround time: (100 + 300 + 600) / 3 = **~333.33**

3. Now do the same, but also with the RR scheduler and a time-slice of 1.

    RR:  
    Response time: (0 + 1 + 2) / 3 = 1  
    Turnaround time:  
        (99 * 3 + 1) = 298  
        (100 * 3 + 99 * 2 + 1) = 499  
        (100 * 3 + 100 * 2 + 100) = 600  
        (298 + 499 + 600) / 3 = **~465.67**

4. For what types of workloads does SJF deliver the same turnaround times as FIFO?

    Jobs with the same length or increasing lengths deliver identical turnaround times in SJF and FIFO.

5. For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

    Job lengths are all the same and equal to quantum length.

6. What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend?

    Response time is equal to job length so it increases.  
    Length = 100, RT = 100  
    Length = 200, RT = 200  
    Length = 300, RT = 300  

7. What happens to response time with RR as quantum lengths increase? Can you write an equation that gives the worst-case response time, given N jobs?

    Response time decreases while quantum length is less than job length.  
    j = job length, q = quantum length
    Worst RT = (N - 1) * q
