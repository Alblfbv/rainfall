# BONUS1

## EXPLANATIONS

### BINARY BEHAVIOR

- atoi performed on argv1
- if atoi_res <= 9 (signed comparison)
  - => argv2 is copied into a stack buffer up to `atoi_res * 4` bytes
- if `*(buffer + 40) == 0x574f4c46`
  - => `execl("sh", "/bin/sh")`

### EXPLOIT STRATEGY

- issue is : we copy at most `(9 * 4 = 36)` bytes of argv1 into buf, so how to write value `0x574f4c46` at `buf+40`

- as binary representation of negative number is msb == 1, we need to find a value that when multiplied by 4 :

  - msb overflows to the left
  - value without msb 11

- `-1073741813`<sub>10</sub>` * 4`<sub>10</sub>
- `== 11000000000000000000000000001011`<sub>2</sub>` * 100`<sub>2</sub>
  - `= 01100000000000000000000000000101100`<sub>2</sub>
  - Only keeping ls32 bits = `00000000000000000000000000101100`
    - `== 44`

Providing :

- `-1073741813` as argv1
- `0x574f4c46` as 40th-44th bytes of argv2 is a working answer

### RUN COMMAND

```
python -c "print('A' * 40 + '\x57\x4f\x4c\x46'[::-1])" > /tmp/argv1_string
/home/user/bonus1/bonus1 -1073741813 $(cat /tmp/argv1_string)
```
