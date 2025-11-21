#include <stdio.h>

int m = 0;

void function_v(void)
{
    char local_var[520];

    fgets(local_var, 512, stdin);
    printf(local_var);
    if (m == 64) {
        fwrite("Wait what?!\n", 1, 12, stdout);
        system("/bin/sh");
    }
    return;
}

void main(void)
{
    function_v();
    return;
}