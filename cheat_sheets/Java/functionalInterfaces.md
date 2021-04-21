### Functional Interfaces

A normal interface

```java
interface employee{
    void display();
}
class prof implements employee{
    //stuff
}
public static void main(String args[]){
    prof p = new prof();
    p.display()
}
```

A functional interface has only one abstract method

```java
interface employee{
    void display();
}

public static void main(String args[]){
    employee e = new employee(){
        public void display(){
            System.out.println("I am an employee");
        }
    }
    e.display();
}
```

_or_ we can use a `lambda` expression

```java
interface employee{
    void display(String name);
}

interface calcualtor{
    int add(int a, int b);
}

public static void main(String args[]){
   employee e = (name)-> {
       System.out.println("I am a professor too and my name is "+ name);
   }
    e.display("David");
    
    //////////////
   calculator c = (a,b)->{return a+b};
    System.out.println(c.add(3,2));
}
```

