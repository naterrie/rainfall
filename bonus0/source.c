#include <string.h>
#include <stdio.h>
#include <unistd.h>

void p(char *str, char *s)
{
	char buffer[4096];

	puts(s);
	read(0, buffer, 4096);
	*strchr(buffer, '\n') = '\0';
	strncpy(str, buffer, 20);

	return;
}

void pp(char *buffer)
{
	char b[20];
	char a[20];
	unsigned int len;

	p(a, " - ");
	p(b, " - ");

	strcpy(buffer, a);

	len = strlen(buffer);

	buffer[len] = ' ';
	buffer[len + 1] = '\0';

	strcat(buffer, b);
	return;
}


int main(void)
{
	char buffer[42];
	pp(buffer);
	puts(buffer);
	return (0);
}
