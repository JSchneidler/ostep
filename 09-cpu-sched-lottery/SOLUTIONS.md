2. Now run with two specific jobs: each of length 10, but one (job 0) with just 1 ticket and the other (job 1) with 100 (e.g., -l 10:1,10:100).

    a. What happens when the number of tickets is so imbalanced?  
        Jobs with low tickets can be starved.  

    b. Will job 0 ever run before job 1 completes? How often?  
        ~1% of the time.  

    c. In general, what does such a ticket imbalance do to the behavior of lottery scheduling?  
        Low ticket jobs can be starved, high ticket jobs can monopolize CPU.  

3. When running with two jobs of length 100 and equal ticket allocations of 100 (-l 100:100,100:100), how unfair is the scheduler?

    Fairness should approach 1 as the scheduler runs.

4. How does your answer to the previous question change as the quantum size (-q) gets larger?

    It can take longer to approach a fairness value of 1.