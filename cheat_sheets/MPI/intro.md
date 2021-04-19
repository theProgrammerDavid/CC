### How to MPI

Ubuntu 20.04 - 

```bash
sudo apt install mpich
```

```c

#include <mpi.h>

void main( int argc, char** argv ) 
{
    MPI_Init( &argc, &argv );

    /* MPI Stuff */


    MPI_Finalize();
}

```



- The Hello World of MPI

  ```C
  
  #include <mpi.h>
  #include <stdio.h>
  int main(int argc, char *argv[])
  {
      int rank, size; 
      
      MPI_Init(&argc, &argv);
      MPI_Comm_rank(MPI_COMM_WORLD, &rank);
      MPI_Comm_size(MPI_COMM_WORLD, &size);
      
      printf("I am %d of %d\n", rank, size);
      
      MPI_Finalize();
      return 0;
  }
  ```

  The default communicator is the `MPI_COMM_WORLD`. A process is identified by its rank in the group associated with a communicator.

Data Types

> `MPI` has their own stuff coz why not



| MPI Datatype | C Datatype  |
| ------------ | ----------- |
| MPI_CHAR     | signed char |
|MPI_CHAR					|			signed char|
|MPI_SIGNED_CHAR			|	signed char|
|MPI_UNSIGNED_CHAR	|		unsigned char|
|MPI_SHORT			|					signed short|
|MPI_UNSIGNED_SHORT	|	unsigned short|
|MPI_INT			|						signed int|
|MPI_UNSIGNED		|				unsigned int|
|MPI_LONG			|					signed long|
|MPI_UNSIGNED_LONG	|	unsigned long|
|MPI_FLOAT						|		float|
|MPI_DOUBLE			|				double|
|MPI_LONG_DOUBLE			|	long double|

###### MPI Blocking send

```c++
MPI_SEND(void *start, int count,MPI_DATATYPE datatype, int dest, int tag, MPI_COMM comm)
```

The message buffer is described by (start, count, datatype).
dest is the rank of the target process in the defined communicator.
tag is the message identification number.