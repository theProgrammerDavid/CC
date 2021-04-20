### Anonymous Classes

A nested class that doesn't have any name is known as an anonymous class. An anonymous class must be defined inside another class

```java
abstract class employee{
    public abstract void display();
}

class professor extends employee{
    public void display(){
        System.out.println("I am a professor");
    }
}

public static void main(String args[]){
    professor p = new professor();
    p.display();
}
```

_or_

```java
abstract class employee{
    public abstract void display();
}

public static void main(String args[]){
employee = new employee(){
    public void display(){
System.out.println("I am a professor too!");
    	}
	};
    
    e.display();
}
```

for interfaces

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

_or_

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

