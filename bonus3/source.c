#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    FILE *file;
    char buffer1[65];
    char buffer2[66];

    file = fopen("/home/user/end/.pass", "r");
    memset(buffer1, 0, sizeof(buffer1));
    if (file == NULL || argc != 2)
    {
        return -1;
    }
    else 
    {
        fread(buffer1, 1, 66, file);
        i = atoi(argv[1]);
        buffer1[i] = '\0';
        fread(buffer2, 1, 64, file);
        fclose(file);
        i = strcmp(buffer1, argv[1]);
        if (i == 0)
        {
            execl("/bin/sh", "sh", NULL);
        }
        else
        {
            puts(buffer2);
        }
        return 0;
    }
    return 0;
}