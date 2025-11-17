#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int compare;
    compare = atoi(argv[1]);
    if (compare == 423)
        printf("flag\n");
    else
        printf("NO !\n");
    return (0);
}