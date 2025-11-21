#include <stdio.h>
#include <stdlib.h>



void function_o(void)
{
    system("/bin/sh");
    _Exit(1);
}

void function_n(void)
{
    char local_var[520];

    fgets(local_var, 512, stdin);
    printf(local_var);

    exit(1);
}

void main(void)
{
    function_n();
    return;
}