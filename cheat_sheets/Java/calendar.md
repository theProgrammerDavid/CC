### Calendar

- Get day (`JAVA 8` only)

  ```java
  import java.time.*; 
  
  public String findDay(int month, int day, int year) {
         LocalDate dt = LocalDate.of(year, month, day);
          return ""+dt.getDayOfWeek();
      }
  ```

  