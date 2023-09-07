1. How should page-table size change as the address space grows? As the page size grows? Why not use big pages in general?

    Length of page table = address space / page size  
    Big pages can increase internal fragmentation  

2. What happens as you increase the percentage of pages that are allocated in each address space?

    More memory references are valid.

3. Which of these parameter combinations are unrealistic? Why?

    `-P 1m -a 256m -p 512m -v -s 3` has too large of a page size

4. Can you find the limits of where the program doesn’t work anymore? For example, what happens if the address-space size is bigger than physical memory?

    Certain pages will not fit in memory and won't be accessible.