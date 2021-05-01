### Regex



- Starts with vowel

  ```sql
  SELECT DISTINCT city FROM station WHERE city REGEXP "^[aeiou].*";
  ```

- does not start with vowel:

  ```sql
  WHERE city NOT RLIKE "^[aeiou].*"
  ```

- ends in vowel

  ```sql
  [aeiou]$
  ```

- starts and ends with vowel

  ```sql
  ^[aeiou].*[aeiou]$
  ```

  