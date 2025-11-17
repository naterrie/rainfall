#include <stdio.h>

void run(void)
{
    fwrite("Good... Wait what?\n", 1, 20, stdout);
    system("/bin/sh");
    return;
}

void main(void)
{
    char arg[76];
    gets(arg);
}