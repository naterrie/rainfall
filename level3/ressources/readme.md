## LEVEL 3 HELP

the level3 binary make a `fgets` call to get user input on a buffer of 520 bytes.

the binary set a global variable named `m` to the value of `0` at the start of the program.

the binary make a printf call to print the content of the buffer after the fgets call.

the printf call use the format string contained in the buffer, leading to a format string vulnerability.

### USAGE

```bash
./level3
[input]
```

### SOLUTION
``` bash
(python -c 'print("m_global_addr" +"a"*60+ "%4$n")'; cat -) | ./level3
```

### COMMAND EXPLANATION

- `[m global addr]` : replace this with the address of the global variable `m` in little endian format (you can find it using gdb or objdump) the address used is `\x8c\x98\x04\x08`

- `a*60` : padding to reach the position of the format string that will write to the address of `m`

- `%4$n` : write the number of bytes written so far to the address of `m`, setting it to a non-zero value to bypass any checks in

- `cat -` : don't close the stdin after the command execution

- `()` : the scope to execute the command `cat` with result of `python`

## USED PARAMETERS

`m_global_addr` = `\xf4\x84\x04\x08`
