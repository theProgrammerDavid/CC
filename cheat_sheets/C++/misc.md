# Misc C++ STL Stuff

- max element in a container

  ```c++
  vector<int> vec;
  auto it = max_element(vec.begin(), vec.end());
  
  int ans = *it;
  ```




- `<limits.h>` is pretty useful

| CONSTANT   | SIZE                 | DESCRIPTION                                                  |
| ---------- | -------------------- | ------------------------------------------------------------ |
| CHAR_BIT   | 8                    | Defines the number of bits in a byte.                        |
| SCHAR_MIN  | -128                 | Defines the minimum value for a signed char.                 |
| SCHAR_MAX  | +127                 | Defines the maximum value for a signed char.                 |
| UCHAR_MAX  | 255                  | Defines the maximum value for an unsigned char.              |
| CHAR_MIN   | -128                 | Defines the minimum value for type char and its value will be equal  to SCHAR_MIN if char represents negative values, otherwise zero. |
| CHAR_MAX   | +127                 | Defines the value for type char and its value will be equal to  SCHAR_MAX if char represents negative values, otherwise UCHAR_MAX. |
| MB_LEN_MAX | 16                   | Defines the maximum number of bytes in a multi-byte character. |
| SHRT_MIN   | -32768               | Defines the minimum value for a short int.                   |
| SHRT_MAX   | +32767               | Defines the maximum value for a short int.                   |
| USHRT_MAX  | 65535                | Defines the maximum value for an unsigned short int.         |
| INT_MIN    | -2147483648          | Defines the minimum value for an int.                        |
| INT_MAX    | +2147483647          | Defines the maximum value for an int.                        |
| UINT_MAX   | 4294967295           | Defines the maximum value for an unsigned int.               |
| LONG_MIN   | -9223372036854775808 | Defines the minimum value for a long int.                    |
| LONG_MAX   | +9223372036854775807 | Defines the maximum value for a long int.                    |
| ULONG_MAX  | 18446744073709551615 | Defines the maximum value for an unsigned long int.          |

```c++
  cout << INT_MAX << INT_MIN;
```

