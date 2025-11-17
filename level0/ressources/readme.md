## LEVEL 0 HELP

the level0 binary only check the first argument after the executable name.

### USAGE

```bash
./level0 <string>
```

next the binary will check if the string is equal to `423` using `atoi` function. If it is the case the program will execute the command `/bin/sh` with the group privileges.

## SOLUTION

To solve this level, simply run the binary with the argument `423`:

```bash
./level0 423
```