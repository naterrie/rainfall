#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
    char buffer[40];
    int local_var = 0;

    local_var = atoi(argv[1]);
    if (local_var < 10)
    {
        memcpy(buffer, argv[2], local_var  * 4);
        if (local_var == 1464814662)
        {
            execl("/bin/sh", "sh", NULL);
        }
        return (0);
    }
    else
    {
        return (1);
    }
    return (0);
}