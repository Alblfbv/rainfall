# LEVEL0

## EXPLANATIONS

### BINARY BEHAVIOR

- ATOI function on `argv[1]` which return value is compared to `0x1a7`<sub>16</sub> (423<sub>10</sub>)
- if cmp is passed then `system("/bin/sh")` is called

### EXPLOIT STRATEGY

- Input 423 as argv1 and a level1 shell will be opened

### RUN COMMAND

```
./level0 423
```
