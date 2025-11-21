#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void m(void)
{
	puts("Nope");
	return;
}

void n(void)
{
	system("/bin/cat /home/user/level7/.pass");
	return;
}

int main(int argc, char **argv)
{
	char *str;
	void (*func_ptr)(void);

	str = (char *)malloc(64);
	func_ptr = malloc(4);
	func_ptr = m;
	strcpy(str, argv[1]);
	func_ptr();
	return (0);
}
