# LEVEL7

## EXPLANATIONS

### BINARY BEHAVIOR

- 2 functions : `main` and `m`
  - `main` function
    - buf1 and buf2 both heap allocated with 8 bytes (heap1 and heap3)
      - => filled respectively with 0x1 and 0x2 on the first bytes of heap
    - two other heap buffers (heap2 and heap4) are allocated
      - => their address are stored at the 4th bytes respectively in buf1 and buf2
    - calls `strcpy` of argv1 into `*(buf1 + 4)` (== heap2)
    - calls `strcpy` of argv2 into `*(buf2 + 4)` (== heap4)
    - `open` /home/user/level8/.pass
    - `fgets` content of .pass
    - `puts('~~')`
  - `m` function
    - `printf()`

### EXPLOIT STRATEGY

Goal here is to overwrite Global Offset Table address of `puts@plt` with `m` function address.  
In main function, fgets writes content of .pass file into a buffer
If we manage to call `m` function, it will print the content of this buffer.

- First call to strcpy copies from start of heap2 (buf1 + 4) an unlimited number of bytes.
  - we overflow up to (buf2 + 4)(== where heap4 address is stored) and replace it with addr GOT puts (thanks to argv1)
  - STRCPY1 :
    - DEST : buf1 + 4 == heap2 => overflows to heap3 + 4 (WILL WRITE INTO HEAP3+4)
    - SRC : argv1 (padding to access heap3+4 + addr puts GOT)
- Second call to strcpy stores m address (argv2) into puts GOT addr
  - STRCPY2 :
    - DEST : buf2 + 4 (previously heap4) now points to puts GOT
    - SRC : argv2 (addr of m)

### RUN COMMAND

```
python -c "print('A' * 20 + '\x08\x04\x99\x28'[::-1])" > /tmp/argv1_string
python -c "print('\x08\x04\x84\xf4'[::-1])" > /tmp/argv2_string
/home/user/level7/level7 $(cat /tmp/argv1_string) $(cat /tmp/argv2_string)
```
