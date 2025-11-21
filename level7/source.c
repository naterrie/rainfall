#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char c[80];

typedef struct {
    int a;
    char *s;
} MyStruct;

void fucntion_m(void *param1, int param2, char *param3, int param4, int param5)
{
    time_t t = time((time_t *)0);
    printf("%s - %d\n", c, (int)t);
    return;
}

int main(int argc, char *argv[])
{
    MyStruct *string_table1;
    MyStruct *string_table2;
    FILE *_stream;

    string_table1 = (MyStruct *)malloc(sizeof(MyStruct));
    string_table1->a = 1;
    string_table1->s = malloc(8);
    string_table2 = (MyStruct *)malloc(sizeof(MyStruct));
    string_table2->a = 2;
    string_table2->s = malloc(8);
    strcpy(string_table1->s, argv[1]);
    strcpy(string_table2->s, argv[2]);
    _stream = fopen("/home/user/level8/.pass", "r");
    fgets(c, 68, _stream);
    puts("~~");
    return 0;
}