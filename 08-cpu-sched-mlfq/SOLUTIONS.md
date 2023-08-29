2. How would you run the scheduler to reproduce each of the examples in the chapter?

    8.2  `-l 0,200,0`  
    8.3  `-l 0,200,0:100,20,0`  
    8.4  `-l 0,200,0:50,25,1 -S`  
    8.5a `-l 0,200,0:100,50,5:100,50,5 -i 1 -S`  
    8.5b `-l 0,200,0:100,50,5:100,50,5 -i 1 -B 50 -S`  
    8.6a `-l 0,200,0:80,75,9 -i 1 -S`  
    8.6b `-l 0,200,0:80,75,9 -i 1`  
    8.7  `-l 0,150,0:0,150,0 -Q 10,20,40`  

3. How would you configure the scheduler parameters to behave just like a round-robin scheduler?

    `-n 1`

4. Craft a workload with two jobs and scheduler parameters so that one job takes advantage of the older Rules 4a and 4b (turned on with the -S flag) to game the scheduler and obtain 99% of the CPU over a particular time interval.

    `-l 0,150,9:0,150,0 -i 0 -S`

5. Given a system with a quantum length of 10 ms in its highest queue, how often would you have to boost jobs back to the highest priority level (with the -B flag) in order to guarantee that a single long- running (and potentially-starving) job gets at least 5% of the CPU?

    200ms