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

- ​ The Hello World of MPI

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

| MPI Datatype       | C Datatype     |
| ------------------ | -------------- |
| MPI_CHAR           | signed char    |
| MPI_CHAR           | signed char    |
| MPI_SIGNED_CHAR    | signed char    |
| MPI_UNSIGNED_CHAR  | unsigned char  |
| MPI_SHORT          | signed short   |
| MPI_UNSIGNED_SHORT | unsigned short |
| MPI_INT            | signed int     |
| MPI_UNSIGNED       | unsigned int   |
| MPI_LONG           | signed long    |
| MPI_UNSIGNED_LONG  | unsigned long  |
| MPI_FLOAT          | float          |
| MPI_DOUBLE         | double         |
| MPI_LONG_DOUBLE    | long double    |

###### MPI Blocking send

```c++
MPI_SEND(void *start, int count,MPI_DATATYPE datatype, int dest, int tag, MPI_COMM comm)
```

The message buffer is described by (start, count, datatype).
dest is the rank of the target process in the defined communicator.
tag is the message identification number.

###### MPI Blocking receive

```C++
MPI_RECV(void *start, int count, MPI_DATATYPE datatype, int source, int tag, MPI_COMM comm, MPI_STATUS *status)
```

- Source is the rank of the sender in the communicator.

- The receiver can specify a wildcard value for source (`MPI_ANY_SOURCE`) and/or a wildcard value for tag (`MPI_ANY_TAG`), indicating that any source and/or tag are acceptable

- Status is used for exrtra information about the received message if a wildcard receive mode is used.

- If the count of the message received is less than or equal to that described by the MPI receive command, then the message is successfully received. Else it is considered as a buffer overflow error.

- `MPI_STATUS` is a `C struct`

[Sample Program](https://github.com/theProgrammerDavid/VIT-LABs/blob/master/MPI/two.c)

> Compile Instructions
> `mpicc ./sample.c`
>
> Run with 4 hosts
> `mpirun -n 4 ./a.out`

```c
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
    const int tag = 42; /* Message tag */
    int id, ntasks, source_id, dest_id, err, i;
    MPI_Status status;
    int msg[2]; /* Message array */

    err = MPI_Init(&argc, &argv); /* Initialize MPI */
    if (err != MPI_SUCCESS)
    {
        printf("MPI initialization failed!\n");
        exit(-1);
    }
    err = MPI_Comm_size(MPI_COMM_WORLD, &ntasks); /* Get nr of tasks */
    err = MPI_Comm_rank(MPI_COMM_WORLD, &id);     /* Get id of this process */
    if (ntasks < 2)
    {
        printf("You have to use at least 2 processors to run this program\n");
        MPI_Finalize(); /* Quit if there is only one processor */
        exit(MPI_SUCCESS);
    }
    if (id == 0)
    { /* Process 0 (the receiver) does this */
        for (i = 1; i < ntasks; i++)
        {
            err = MPI_Recv(msg, 2, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD,
                           &status);       /* Receive a message */
            source_id = status.MPI_SOURCE; /* Get id of sender */
            printf("Received message %d %d from process %d\n", msg[0], msg[1],
                   source_id);
        }
    }
    else
    {                    /* Processes 1 to N-1 (the senders) do this */
        msg[0] = id;     /* Put own identifier in the message */
        msg[1] = ntasks; /* and total number of processes */
        dest_id = 0;     /* Destination address */
        err = MPI_Send(msg, 2, MPI_INT, dest_id, tag, MPI_COMM_WORLD);
    }

    err = MPI_Finalize(); /* Terminate MPI */
    if (id == 0)
        printf("Ready\n");
    exit(0);
    return 0;
}
```

- Non blocking send and receive

  ```c++
  MPI_ISEND(buf, count, datatype, dest, tag, comm, request)
  MPI_IRECV(buf, count, datatype, dest, tag, comm, request)
  ```

  A non-blocking send call indicates that the system may start copying data out of the send buffer. The sender must not access any part of the send buffer after a non-blocking send operation is posted, until the complete-send returns.

  A non-blocking receive indicates that the system may start writing data into the receive buffer. The receiver must not access any part of the receive buffer after a non-blocking receive operation is posted, until the complete-receive returns.

  `MPI_WAIT (request, status) MPI_TEST (request, flag, status)`

  The `MPI_WAIT` will block your program until the non-blocking send/receive with the desired request is done.

  The `MPI_TEST` is simply queried to see if the communication has completed and the result of the query (`TRUE` or `FALSE`) is returned immediately in flag.

Collective Operations

- `MPI_Bcast`

  `MPI_Bcast` distributes data from one process(the root) to all others in a communicator.

  Syntax:
  `MPI_Bcast(void *message, int count, MPI_Datatype datatype, int root, MPI_Comm comm)`

- `MPI_Reduce`MPI_Reduce combines data from all processes in communicator or and returns it to one process

  Syntax:
  `MPI_Reduce(void *message, void *recvbuf, int count, MPI_Datatype datatype, MPI_Op op, int root, MPI_Comm comm)`

### Sample Broadcase Program

> Compile Instructions
> `mpicc ./sample.c`
>
> Run with 4 hosts
> `mpirun -n 4 ./a.out`

```c++
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
void my_bcast(void *data, int count, MPI_Datatype datatype, int root, MPI_Comm communicator)
{
    int world_rank;
    MPI_Comm_rank(communicator, &world_rank);
    int world_size;
    MPI_Comm_size(communicator, &world_size);

    if (world_rank == root)
    {
        int i;
        for (i = 0; i < world_size; i++)
        {
            if (i != world_rank)
            {
                MPI_Send(data, count, datatype, i, 0, communicator);
            }
        }
    }
    else
    {
        MPI_Recv(data, count, datatype, root, 0, communicator, MPI_STATUS_IGNORE);
    }
}
int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int data;
    if (world_rank == 0)
    {
        data = 100;
        printf("Process 0 broadcasting data %d\n", data);
        my_bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }
    else
    {
        my_bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
        printf("Process %d received data %d from root process\n", world_rank, data);
    }

    MPI_Finalize();
}
```
