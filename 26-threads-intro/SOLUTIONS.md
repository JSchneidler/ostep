1. Let’s examine a simple program, `loop.s`. First, just read and understand it. Then, run it with these arguments `-p loop.s -t 1 -i 100 -R dx`. This specifies a single thread, an interrupt every 100 instructions, and tracing of register `%dx`. What will `%dx` be during the run? The answers, on the left, show the value of the register (or memory value) after the instruction on the right has run.

    0, -1

2. Same code, different flags: `-p loop.s -t 2 -i 100 -a dx=3,dx=3 -R dx`. This specifies two threads, and initializes each `%dx` to 3. What values will `%dx` see? Does the presence of multiple threads affect your calculations? Is there a race in this code?

    3, 2, 1, 0, -1  
    No  
    No  

3. Run this: `-p loop.s -t 2 -i 3 -r -a dx=3,dx=3 -R dx`. This makes the interrupt interval small/random; use different seeds (`-s`) to see different interleavings. Does the interrupt frequency change anything?

    No, all data access is through registers.

4. Now, a different program, `looping-race-nolock.s`, which accesses a shared variable located at address 2000; we’ll call this variable value. Run it with a single thread to confirm your understanding: `-p looping-race-nolock.s -t 1 -M 2000`. What is value (i.e., at memory address 2000) throughout the run?

    0, 1

5. Run with multiple iterations/threads: `-p looping-race-nolock.s -t 2 -a bx=3 -M 2000`. Why does each thread loop three times? What is final value of value?

    The loop is based on `bx` register, not a shared value.  
    6

6. Run with random interrupt intervals: `-p looping-race-nolock.s -t 2 -M 2000 -i 4 -r -s 0` with different seeds (`-s 1`, `-s 2`, etc.) Can you tell by looking at the thread interleaving what the final value of value will be? Does the timing of the interrupt matter? Where can it safely occur? Where not? In other words, where is the critical section exactly?

    Yes, though it would become more difficult and impractical as thread count and iterations grow.  
    Timing matters. If during a critical section, result can be indeterminate.  
    Critical section is line 6-8, where the increment occurs.

7. Now examine fixed interrupt intervals: `-p looping-race-nolock.s -a bx=1 -t 2 -M 2000 -i 1`. What will the final value of the shared variable value be? What about when you change `-i 2`, `-i 3`, etc.? For which interrupt intervals does the program give the “correct” answer?

    1  
    1 when i = 2, 2 when i = 3  
    i >= 3

8. Run the same for more loops (e.g., set `-a bx=100`). What interrupt intervals lead to a correct outcome? Which intervals are surprising?

    i % 3 = 0

9. One last program: `wait-for-me.s`. Run: `-p wait-for-me.s -a ax=1,ax=0 -R ax -M 2000`. This sets the `%ax` register to 1 for thread 0, and 0 for thread 1, and watches `%ax` and memory location 2000. How should the code behave? How is the value at location 2000 being used by the threads? What will its final value be?

    It should run different code based on the value in address 2000.  
    Value at 2000 is being used as a flag by the threads to determine which code to run.  
    1

10. Now switch the inputs: `-p wait-for-me.s -a ax=0,ax=1 -R ax -M 2000`. How do the threads behave? What is thread 0 doing? How would changing the interrupt interval (e.g., -i 1000, or perhaps to use random intervals) change the trace outcome? Is the program efficiently using the CPU?

    Thread 0 becomes the waiter, but has to wait until a interrupt occurs to allow thread 1 to run and set address 2000 to 1. Thread 0 can then finish.  
    Lowering interrupt interval would cause thread 0 to wait less time.  
    Program is not efficiently using CPU.