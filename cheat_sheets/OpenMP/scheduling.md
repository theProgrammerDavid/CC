# OpenMp Scheduling

- `static`: Threads are allocated iterations before they execute the loop iterations. The iterations are divided among threads equally by default. 

- `dynamic`: Some of the iterations are allocated to a smaller number of threads. Once a particular thread finishes its allocated iteration, it returns to get another one from the iterations that are left. 

- `guided`: A large chunk of contiguous iterations are allocated to each thread dynamically    
