### Dates

- Write an SQL query to convert each date in `Days` into a string formatted as `"day_name, month_name day, year"`

  ```sql
  SELECT DATE_FORMAT(day, "%W, %M %e, %Y") AS day
  FROM Days
  ```

  

