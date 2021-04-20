### Threads 

There are 4 ways to create a thread in Java

- Inheriting from the `Thread` class
- Implementing the `Runnable` interface
- Anonymous functions 
- Lambda Expressions

Once you start a `Thread`, you must either `join()` it or `detach()` it. `join()` makes the `main` thread wait for it to finish whereas `detach()` allows the `main` thread to continue with execution 

##### Inheriting from Thread

```java
public class someClass extends Thread{
    @Override
    public void run(){
        // stuff to do 
    }
    
    public someClass(String name){
        super(name)
    }
}


public static void main(string args[]){
    someClass c = new someClass("threadName");
    //thread c has name 'threadName'
    c.start();
    System.out.println(c.getName());
    
    //setting name of thread
    c.setName("name_123");
    
    c.join();
}
```

> Similarly with `getId()`  and `setId()`

##### Implementing a Runnable Interface

```java
public class someClass implements Runnable{
    @Override
    public void run(){
        //some stuff to do 
    }
}

public static void main(String args[]){
    someClass c = new someClass();
    Thread t = new Thread(c);
    //we pass an object of type Runnable
    
    t.start();
    t.join();
}
```



##### Anonymous classes 

```java
public static void main(String args[]){
        
    Thread t = new Thread(new Runnable(){
        @Override
		public void run(){
            //do stuff here
        }
    });
    /* 
    new Object(){
    declares an anonymous inner class of type Object
    }
    */
    
    t.start();
    t.join();
}
```

> Anonymous inner classes still follow the rules of scope 

##### Lambda Expressions

```java
/*
the Runnable interface looks like

interface Runnable{
	public abstract void run();
}
*/

public static void main(String args[]){
        
 Runnable r = ()->{System.out.println("I am a thread from a lambda");};
    Thread t = new Thread(r);
        
    t.start();
    t.join();
}
```



##### Priority among threads 

10 (`MAX_PRIORITY`) 
5 (`NORMAL_PRIORITY`) 
1 (`MIN_PRIORITY`)

```java
public static void main(String args[]){
        
    Thread t = new Thread(new Runnable(){
        @Override
		public void run(){
            //do stuff here
        }
    });
    
    t.start();
    ////////
    
    t.setPriority(1);
    System.out.println(t.getPriority);
    
    ////////
    t.join();
}
```

Current Thread
``System.out.println("current thread is : "+Thread.currentThread().getName());``



##### Synchronized

Only functions can be declared as `synchronized`. Declare a function as `synchronized` when you want it to be a `critical` section - when you want only one thread to read/modify resources at one time.

```java
class Account{
    private void accountBalance;
    synchronized public void addMoney(int amount){
        this.Balance +=amount;
    }
}
```

Alternatively, you can declare a `synchronized` block within a function if you don't want the entire function to be a critical section 

```java
class Account{
    private void accountBalance;
    public void addMoney(int amount){
        //some other stuff
        
        synchronized(this){
            this.Balance +=amount;
        }
        
        //more stuff
    }
}
```

`Static synchronized` blocks `synchronize` on the class object and `non static` `synchronized` objects `synchronize` on the class instances.

##### Sleep

``Thread.currentThread().sleep(milliseconds)``

```java
public class someClass implements Runnable{
    @Override
    public void run(){
        //some stuff to do 
        Thread.currentThread().sleep(9000); // 9s
    }
}

public static void main(String args[]){
    someClass c = new someClass();
    Thread t = new Thread(c);
    t.start();
    t.join();
}
```



##### `wait()`, `notify()` and `notifyAll()`

The `wait()` method causes the current thread to wait until another thread calls the `notify()` or `notifyAll()` functions for that object. 

The `notify()` wakes up a single `thread` that is waiting on the object's monitor. 

The `notifyAll()` method wakes up **all** threads that are waiting on the object's monitor