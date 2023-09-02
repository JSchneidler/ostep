2. Now, let’s see if we understand this tiny address space we’ve constructed (using the parameters from the question above).  
    What is the highest legal virtual address in segment 0?  
        19  
    What about the lowest legal virtual address in segment 1?  
        108  
    What are the lowest and highest illegal addresses in this entire address space?  
        20, 107  
    Finally, how would you run segmentation.py with the -A flag to test if you are right?  
        `-a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -A 19,108,20,107 -c`  

3. Let’s say we have a tiny 16-byte address space in a 128-byte physical memory. What base and bounds would you set up so as to get the simulator to generate the following translation results for the specified address stream: valid, valid, violation, ..., violation, valid, valid? Assume the following parameters: `segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 ? --l0 ? --b1 ? --l1 ?`

    `--b0 0 --l0 2 --b1 127 --l1 2`

4. Assume we want to generate a problem where roughly 90% of the randomly-generated virtual addresses are valid (not segmentation violations). How should you configure the simulator to do so? Which parameters are important to getting this outcome?

    `-a 10 -p 20 -b 0 -l 4 -B 10 -L 4 -s 6 -c`

5. Can you run the simulator such that no virtual addresses are valid? How?

    `-a 16 -p 128 -b 0 -l 0 -B 64 -L 0 -c`