### Files

>  tldr - `writers` write text files, `streams` write binary files

```java
  File(String Path);
  File (Stirng Parent, String Child); // new File('path', 'filename')
  File(File Parent, String Child);// new File(new File('some path to folder'), 'fileName.txt')
  
  File obj = new File("/home/david/hello.txt");
  System.out.println(obj.getName());
  System.out.println(obj.separator);
  System.out.println(obj.getAbsolutePath());
  
  System.out.println(obj.getPath());
  System.out.println(obj.exists());
  System.out.println(obj.isDirectory());
  System.out.println(obj.isAbsolute());
  System.out.println(obj.canRead());
  System.out.println(obj.canWrite());
  
  
  String arr[] = obj.listFiles();
  
  //if file does not exist
  if(obj.createNewFile()){
      // do something
  }
```

![Types of streams](https://cdn.programiz.com/sites/tutorial2program/files/java%20inputstream-subclasses.png)

<hr>

![Types of Output Streams](https://cdn.programiz.com/sites/tutorial2program/files/java%20outputstream-subclasses.png)

- FileOutputStream

  ```java
  File obj = new File("stuff.txt");
  FileOutputStream fout = new FileOutputStream(obj);
  ```

  Constructor definitions

  ```java
  FileOutputStream(File file)
  FileOutputStream(File file, boolean append)
  FileOutputStream(String name)
      
  // other functions
  write(byte[] b)
  write(byte[] b, int off, int len)
  // writes len bytes from b starting at offset
      
  write(int b)
  close()
  ```

  

  Sample Program:

  ```java
  FileInputStreamtry{
      FileOutputStream fout = new FileOutputStream('stuff.txt');
      String s = "Hello World";
      fout.write(s);
      fout.write(420);
      fout.close();
  }
  catch(Exception e){
      System.out.println(e);
  }
  ```

  

- FileInputStream 

  ```java
  FileInputStream fin = new FileInputStream(new File("stuff.txt"));
   	int i=0;    
      while((i=fin.read())!=-1){    
          System.out.print((char)i);    
      }    
  
  //you read stuff one int at a time
  
  fin.close();
  ```

  

| Method                                 | Description                                                  |
| -------------------------------------- | ------------------------------------------------------------ |
| int available()                        | It is used to return the estimated number of bytes that can be read from the input stream. |
| `int read()`                           | It is used to read the byte of data from the input stream.   |
| `int read(byte[] b)`                   | It is used to read up to `b.length` bytes of data from the input stream. |
| `int read(byte[] b, int off, int len)` | It is used to read up to `len` bytes of data from the input stream. |
| `long skip(long x)`                    | It is used to skip over and discards x bytes of data from the input stream. |
| `FileChannel getChannel()`             | It is used to return the unique `FileChannel` object associated with the file input stream. |
| `FileDescriptor getFD()`               | It is used to return the [FileDescriptor](https://www.javatpoint.com/java-filedescriptor-class) object. |
| `protected void finalize()`            | It is used to ensure that the close method is call when there is no more reference to the file input stream. |
| `void close()`                         | It is used to closes the [stream](https://www.javatpoint.com/java-8-stream). |





- FileReader

  ```java
  FileReader(File file)
  FileReader(String fileName)
      
  public int read() throws IOException
  public int read(charp[ buf])throws IOException
  public int read(char buf[], int of, int l)
  public void close();
  ```

  Sample program: 

  ```java
  FileReader fin = new FileReader(new File("stuff.txt"));
  
  char[] array = new char[100];
  
      try {
        // Creates a reader using the FileReader
        FileReader input = new FileReader("input.txt");
  
        // Reads characters
        input.read(array);
        System.out.println("Data in the file: ");
        System.out.println(array);
  
        // Closes the reader
        input.close();
      }
  
      catch(Exception e) {
        e.getStackTrace();
      }
  ```

  

- FileWriter

  ```java
  FileWriter fw = new FileWriter(new File("stuff.txt"));
  char c[] = {'h','e','l','o','o'};
  String s = "Hello world";
  fw.write(c);
  fw.write(s);
  fw.close();
  ```

  

- InputStreamReader

  ```java
  File f = new File("stuff.txt");
  FileInputStream fin = new FileInputStream(f);
  InputStreamReader is = new InputStreamReader(fin, "UTF-16");
  
  int data = is.read();
  System.out.println((char)data);
  ```

  

- OutputStreamWriter

  ```java
  OutputStreamWriter os = new OutputStreamWriter(new FileOutputStream(new File("stuff.txt")));
  
  os.write(1013);
  char c[] = {'h','e','l','l','o'};
  os.write(c);
  ```

  

- Object Serialisation

  ```java
  Student t = new Student("Jack", 123);
  //t should implement Serializable interface
  File f= new new File("stuff.txt");
  FileOutputStream fout = new FileOutputStream(fout);
  
  ObjectOutputStream oo = new ObjectOutputStream(fout);
  
  // write object to file
  oo.write(t);
  oo.close();
  
  ```

- Object De-Serialisation 

  ```java
  FileInputStream name = new FileInputStream(new File("stuff.txt"));
  ObjectInputStream in = new ObjectInputStream(name);
  
  Student s = null;
  s = (Student) in.readObject();
  
  ```

  