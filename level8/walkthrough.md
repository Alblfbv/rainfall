# LEVEL8

## EXPLANATIONS

### BINARY BEHAVIOR

- `main` function  
   while loop that prints addresses of two variable (auth and service)
  - `fgets` stdin into a stack buffer
  - cmp buf to strings("auth ", "service ", "reset", "login")
    - if "auth" :
      - malloc
      - if len of string after auth is less than 30 => strcpy buf into variable auth (to prevent write after 30 bytes in the stack)
    - if "service" :
      - strdup buf into var service
    - if "reset" :
      - free the variable auth
    - if "login" :
      - if the address at auth + 0x20 (32)is not NULL :
      - `system("/bin/sh")`

### EXPLOIT STRATEGY

- So we want to access `system("/bin/sh")`
  - if We type 'auth ' it will allocate a heap buffer and set var auth to the address of this heap buffer.
  - Then if we type 'service ' + more than 20 padding char, it will copy the string into another heap buffer (and \*(auth + 20) will not be NULL anymore)
  - Finally login to enter the system call

DONE
