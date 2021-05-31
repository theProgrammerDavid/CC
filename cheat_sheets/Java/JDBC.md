### JDBC



- ##### Installation

  Go to [this link](https://dev.mysql.com/downloads/connector/j/) and select `Platform Independent` and download either the `zip` or the `tar` and extract the `jar` file to the directory with your `class` files.

- ##### Usage

  Use the command line argument `-cp .:<name of jar file>` 

  Your source code can now look like this 

  ```java
  import java.sql.Connection;
  import java.sql.DriverManager;
  import java.sql.SQLException;
  import java.sql.Statement;
  
  public class test1 {
     static final String DB_URL = "jdbc:mysql://localhost:6603/";
     static final String USER = "user";
     static final String PASS = "password123";
  
     public static void main(String[] args) {
        // Open a connection
        try(Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
           Statement stmt = conn.createStatement();
        ) {		      
           String sql = "CREATE DATABASE STUDENTS";
           stmt.executeUpdate(sql);
           System.out.println("Database created successfully...");   	  
        } catch (SQLException e) {
           e.printStackTrace();
        } 
     }
  }
  ```

  