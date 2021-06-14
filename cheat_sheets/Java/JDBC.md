### JDBC



- ##### Installation

  Go to [this link](https://dev.mysql.com/downloads/connector/j/) and select `Platform Independent` and download either the `zip` or the `tar` and extract the `jar` file to the directory with your `class` files.

- ##### Usage

  Use the command line argument `-cp .:<name of jar file>` 

  ```bash
  javac test1.java
  java -cp .:mysql-connector-java-8.0.25.jar test1
  ```

  

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

  

![jdbc statement execution](https://i.stack.imgur.com/V6fjm.png)



- Result Set

```java
Statement st = conn.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
        ResultSet rs = st.executeQuery(s);

if (rs.next()==false){
    System.out.println("empty");
}
else{
    rs.previous();
    System.out.println(rs.getString(1) + rs.getString(2) + ...);
}
```



- Prepared Statement

  ```java
   public boolean insert(Connection con) throws SQLException {
          PreparedStatement ps = con.prepareStatement("INSERT INTO STUDENTS VALUES(?,?,?,?,?);");
          ps.setString(1, name);
          ps.setString(2, password);
          ps.setString(3, gender);
          ps.setString(4, country);
          ps.setString(5, subject);
  
          int i = ps.executeUpdate();
          System.out.println(i);
  
          return i > 0;
      }
  ```

  