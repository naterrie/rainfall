#include <stdio.h>
#include <stdlib.h>

void pFunction(void)
{
    char var2[76];

    fflush(stdout);
    gets(var2);
    if ((&var2 & 0xb0000000) == 0xb0000000)
    {
        printf("(%p)\n", *var2);
        _exit(1);
    }
    puts(var2);
    strdup(var2);
    return;
}

void main(void)
{
    pFunction();
    return;
}   
