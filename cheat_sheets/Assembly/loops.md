### Loops

- `do while`
  `C`:

  ```c
  int x=1;
  do{
      //stuff
  }
  while(x==1)
  ```

  Assembly:

  ```assembly
  MOV AX, 1
  
  loop1:
  ;STUFF
  CMP AX, 1 	;condition check
  JE loop1	;jump to label 'loop1' if previous compare is true
  ```

  

- `for`


  For the for-loops you should take the cx-register because it is pretty much standard. For the other loop conditions you can take a register of your liking. Of course replace the no-operation instruction with all the instructions you wanna perform in the loop.
  `C`:

```c
for(int x = 0; x<=3; x++)
{
    //Do something!
}
```

Assembly:

```assembly
XOR CX, CX	;set counter to 0

loop1:
; stuff here
INC CX
CMP CX, 3
JLE loop1	;jump whie less then or equal
```



- `while`
  `C`:

```c
while(x==1){
    //stuff
}
```

Assembly:

```assembly
JMP loop1	;jump to the condition first

loop_content:
; stuff 

loop1:
CMP AX, 1
JE loop_content
```

