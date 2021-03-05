# BONUS0

## EXPLANATIONS

### BINARY BEHAVIOR

- pp stack frame :

  - buf_pp[40]

- main stack frame :

  - buf_main[40]

- program is reading two times from stdin, each time for 4096 bytes.
- a large input results in a segmentation fault
- if there is not at list one `\n` in each buf filled by read, results in a segmentation fault
- first 20 bytes of each read are then stored contiguously on pp stack frame (total of 40 bytes)
- those 40 bytes are then copied onto main stack frame
- `" "` is concatenated to main stack buffer
- 2nd read buf is concatenated after those 41 bytes
  - final buffer content : `"read1 + read2 + " " + read2"`
    - => The last `read2` overflows into main sEIP

### EXPLOIT STRATEGY

- the sEIP we can overwrite is the one of main ret instruction (thanks to strcat in pp function)
- We will try to overwrite sEIP with the address of begining of `buf_main` which will contain our shellcode

- Issues are :
  1. providing stdin for 2 separate reads with a script
     - => 4096 (read1) + 20 (read2) in one string to stdin does the trick
  2. buffer is on stack, not heap (unstable stack addresses)
     - => we found that without env and proper path to execute the binary, stack was aligned in/out GDB.
  3. our shellcode is 25 bytes long, it will be split over two inputs.
     - => 20 first in first read, 5 last at start of 2nd read
  4. the second read input is repeated twice + total length of string is odd. Hence, aiming precisely for sEIP was harder than usual.
     - => Solved through trial and error inside gdb

### RUN COMMAND

```
python -c "print('\x31\xc0\x31\xdb\x31\xc9\x31\xd2\xb0\x0b\x53\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62' + 'A' * 4075 + '\n' + '\x69\x89\xe3\xcd\x80' + 'B' * 9 + '\xbf\xbf\xff\xfe\x16'[::-1])" > /tmp/exploit_string
cat /tmp/exploit_string - | env - PWD=$PWD /home/user/bonus0/bonus0
```
