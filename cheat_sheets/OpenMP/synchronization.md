### OpenMP thread Synchronization



OpenMP provides a variety of Synchronization Constructs that control how the execution of each thread proceeds relative to other team threads :

- Master
- Critical
- Atomic
- Barrier
- Ordered
- flush

##### Master

The `master` directive specifies a region that only the master thread can execute.

```c++
#pragma omp master {
// some stuff 
}
```

###### Barrier

The `barrier` directive synchronizes all threads in the team. When a `barrier` directive is reached, a thread will wait till all the other threads have reached that directive 

```c++
#pragma omp parallel
{
int mytid = omp_get_thread_num();
x[mytid] = some_calculation();
#pragma omp barrier
y[mytid] = x[mytid]+x[mytid+1];
}
```

###### Critical

Mutual exclusion. Only one thread at a time can enter a critical region

```c++
float res;
#pragma omp parallel
{
    float B;
    int i,id, nthreads;
    
    id = omp_get_thread_num();
    nthreads = omp_get_num_threads();
    
    for(i=id;i<nthreads;i++){
        B = big_job(i);
        
        #pragma omp critical
        consume(B, res);
    }
}
```

###### Taskwait

The taskwait construct specifies a wait on the completion of child tasks of the current task. It is a stand-alone directive

``#pragma omp taskwait {}``

###### Atomic

The ``Atomic`` construct provides mutual exclusion but only to the variable declared (or rather, memory address) below it

```c++
#pragma omp parallel{
	double tmp, B;
	
	B = xyz();
	tmp = abc();

	#pragma omp atomic
	X += tmp
}
```

###### Ordered

The `ORDERED` directive specifies that iterations of the enclosed loop will be executed in the same order as if they were executed on a serial processor.

Threads will need to wait before executing their chunk of iterations if previous iterations haven't completed yet.

```c++
#pragma omp for ordered [clauses] {
//loop statements
}
```



###### Flush

The `FLUSH` directive identifies a synchronisation point at which the implementation must provide a consistent view of memory. Thread-visible variables are written back to memory at this point

`Flush` is required on a cache coherent system

``#pragma omp flush(list) newline ``

###### if else 

```c++
#pragma omp parallel if(some_val)
{
    if(omp_in_parallel()){
        //some stuff 
    }
    else{
        //some other stuff
    }
}
```

