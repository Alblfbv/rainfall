# BONUS3

## EXPLANATIONS

### BINARY BEHAVIOR

- A buffer is created on the stack
  - .pass of user end copied in buffer
- Runs an atoi(argv1)
- NULL byte written at \*(buffer + atoi_ret)
- strcmp(buf, argv1)
  - if strings are equal => execl("sh", "/bin/sh")

### EXPLOIT STRATEGY

- We understood that argv1 string must be equal to buf string so that strcmp returns 0
- As we don't know the .pass of user end, we cannot provide it as argv1
- If atoi return is 0, it writes NULL on first byte of buf.
- If argv1 is an empty string :
  - atoi return value will be 0
  - argv1 value will be '\0' == NULL byte
  - strcmp(buf, argv1) == strcmp('\0', '\0') => SUCCESS

### RUN COMMAND

./bonus3 ""
