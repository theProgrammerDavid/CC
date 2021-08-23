# OpenMP Introduction 

### - Threads
 - Master Thread has id 0

### - Sections
- The `SECTIONS` directive is a non-iterative work-sharing construct. 
It specifies that the enclosed section(s) of code are to be divided among the threads in the team

- Independent `SECTION` directives are nested within a SECTIONS directive. 
Each `SECTION` is executed once by a thread in the team. Different sections may be executed by different threads. 

- It is possible for a thread to execute more than one section if it is quick 
enough and the implementation permits

### - Single

- The `SINGLE` directive specifies that the enclosed code is to be executed by only one thread in the team.

- May be useful when dealing with sections of code that are not thread safe
- It is illegal to branch into or out of a SINGLE block

### Environment Variables

- `OMP_NUM_THREADS` 