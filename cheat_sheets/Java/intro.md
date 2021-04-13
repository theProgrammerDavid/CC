# Java Cheat Sheet

> Everything you need to know to transition to Java from another language [work in progress]

### Data types

* Primitives - `int, float, double, char, boolean, long, byte, short`

* Java supports scientific notation with float initialisation

```java
float f1 = 35e3f;
double d1 = 12E4d;
```

* Non Primitive - ``java.lang.String`` 
  `Java.lang.String` and `char` are Unicode by default. Provides string manipulation functions

### Everything is a class

> Everything ? <strong>Everything.</strong>

```java
public class Stuff{
    public static void main(String args[]){
        System.out.println("Hello World");
    }
}
```

If you decide to make the  ``Stuff`` class ``public``, it needs to be in a file called ``Stuff.java``
Else, you can have multiple non public classes in a file.

Sysout with `System.out.println` where `System.out` is the default output stream.

> Alternatively, you can use `System.out.print()` if you don't want a newline

<br>

#### Compile and Run !

> Assuming you have a JDK setup

* compile with 

```bash
javac Stuff.java
```

* run with 

```bash
java Stuff arg1 arg2
```

where arg1 and arg2 are your command line arguments which are passed into ``String args[]`` in the ``main`` function.


### String Stuff

```java
int number = 823;
System.out.println(“Today’s lotto number is:  ” + number);

```

```java
String x = "Hello World";
char c = x.charAt(1);
int len = s.length;
String s1 = x.toLowerCase();

String test = "Programming in Java";
String result[]=test.split(" ");
char c[]=test.toCharArray();

char a[]= {'a','b','c'};
String s = new String(a);

System.out.println(test.contains("learning"));
```

* compareTo

compareTo returns

* a negative number if String_1 precedes String_2
* zero if the two strings are equal
* a positive number of String_2 precedes String_1

> Tip: Think of compareTo is subtraction

### Math

```java
import java.lang.Math;

double res1 = Math.pow(base,power);
double res2 = Math.sqrt(base);
double ans = 10*Math.PI;
```

#### Stuff 

* use the ``final``  keyword to declare constants 
* Cannot override methods declared as final (inheritance stuff)
* Cannot inherit classes declared as final
* Array 

```java
System.arraycopy (src,srcindex, dest, destindex , length)
```

* static
  Static members are accessed by the class identifier as opposed to the object identifier

```java
class xyz{
    public int x;
    public static int y;
}
xyz obj = new xyz();
obj.x;
xyz.y;
```

* Arrays
  * Accessing an array element beyond the size will lead to an ``ArrayIndexOutOfBoundsException`` being thrown
  * Unlike ``Python``, negative indexes will not wrap around to the other side
  * The size of the array needs to be known at compile time. Thus, you can initialize an array with a variable as long as the value can be computed at compile time

```java
int arr[] = new int[10];

int constant_size = 18*2 + 5 ;
int p[] = new int[constant_size];

arr = new int[50];
// previous data is discarded

System.out.println(arr.length);
// arr.length is a property of the array, not a function

int[][] array2D = { {99, 42, 74, 83, 100}, 
                    {90, 91, 72, 88, 95}, 
                    {88, 61, 74, 89, 96}, 
                    {61, 89, 82, 98, 93}, 
                    {93, 73, 75, 78, 99}, 
                    {50, 65, 92, 87, 94}, 
                    {43, 98, 78, 56, 99} }; 

// or with varying size arrays
int[][] uneven = { { 1, 9, 4 }, 
                  { 0, 2}, 
                  { 0, 1, 2, 3, 4 } }; 

```

* switch case
  * can use strings, int , char, boolean and not floating point numbers
  * no complex expressions in each case statement, just a constant 

### Error Handling

* All exceptions have ``java.io.Exception`` as a base class and all other exceptions inherit it
* The order in which you catch exceptions matters
* Exceptions thrown are heap allocated
* Once an exception is thrown and if not handled, stack unwinding will take place

| Keyword | Description                                                  |
| ------- | ------------------------------------------------------------ |
| try     | put code that might throw an exception in it                 |
| catch   | specify what kind of exception to catch and what to do once you catch it |
| finally | block of code that always executes irrespective of an exception being thrown |
| throw   | can manually throw an exception                              |
| throws  | used in a function definition to state that this function might throw an exception |

```java
public void some_function() throws IOException {
  // some code that may throw an exception
}
.
.
.

try{  
    //code that may raise exception  
    throw new FileNotFoundException();
    int data=100/0;  
}
catch(Exception e){
  // this will always fire as the order of declaring exceptions matters
}
catch(ArithmeticException e)
{
  System.out.println(e);
  }  
finally{
  //stuff that will always execute
}
```


### User Input

* ``Scanner``

```java
import java.util.*

Scanner sc = new Scanner(System.in);
while(sc.hasNext()){
    sc.nextLine();
    sc.nextInt();
    sc.nextFloat();
    sc.nextDouble();
    sc.nextLong();
    ...
}
```

* [BufferedReader](https://www.geeksforgeeks.org/java-io-bufferedreader-class-java/)
  * Buffers ``Reader`` streams for faster input output

```java
BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
String x = br.readLine();
.
.
.
br.close();
```

#### Packages

* specify ``package xyz;`` at the top of your java files to group together src files present in the same folder under one package.


### Inheritence and stuff

* we use the ``extends`` keyword

```java
class A{

}
class B extends A{

}
```

* ``abstract`` classes cannot be instantiated, only inherited. 
* an ``interface`` is a way Java implements multiple inheritance. You ``implement`` an interface

```java
interface xyz{

}
class A implements xyz{

}
```

* The ``this`` keyword refers to the data member in a current instance. generally used when you have a member variable and a function parameter with the same name. Same as the ``self`` keyword in ``Python``
* The ``super`` keyword refers to the ``parent`` class that the child class inherited from.

#### Nested Classes

```java
class outer
{
	public String a;
	protected String b;
	private string c;
	class inner
	{
		public String in1;
		public void display() {
			System.out.println(a+b+c);
		}
	}
	
	public void displayout() {
		
		System.out.println(a+b+c);
		
	}
}
```

* Nested class can access all members of its outer class
* An outer class cannot access members of its nested class
* Nested classes can be given an access specifier. * The class can be declared either protected, private or public
* A non static nested class is known as inner class
* An inner class can inherit another inner class
* An object can be created for the extended inner class
  <br>

- Object for outer class

```java
outer outobj = new outer();
outobj.displayout();
```

- Object for inner class

```java
outer outobj = new outer();
outer.inner inobj = outobj.new inner();
inobj.display();
```

#### Static nested class

```java
class outer
{
	public int a;
	public static int b;
	static class inner
	{
		public void display() {
			
			System.out.println("am the static class method");
			
		}
	}
}

outer.inner d = new outer.inner();
d.display();
```

* A static nested class cannot access the outer class non static members. 
* A static nested class can access only static members of the outer class

##### Tired of declaring classes ?

>  Anonymous inner classes to the rescue

```java
interface shape
{
	void displaymessage();
}

shape s = new shape()
{
       public void displaymessage()
       {
       System.out.println("hello message");
       }
};

s.displaymessage();
```

#### Finalize what ? 

* The finalize() method of Object class is a method that the Garbage Collector always calls just before the deletion/destroying the object which is eligible for Garbage Collection, so as to perform clean-up activity.

* The syntax for ``finalize`` is 

```java
protected void finalize throws Throwable{}
```

```java
public class demo {
  
    protected void finalize() throws Throwable
    {
        try {
  
            System.out.println("inside demo's finalize()");
        }
        catch (Throwable e) {
  
            throw e;
        }
        finally {
  
            System.out.println("Calling finalize method"
                               + " of the Object class");
  
            // Calling finalize() of Object class
            super.finalize();
        }
    }
}
```