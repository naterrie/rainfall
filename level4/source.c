#include <stdio.h>
#include <stdlib.h>

int	m;

void	p(char *format)
{
	printf(format);
}

void	n(void)
{
	char	buffer[512];

	fgets(buffer, 512, stdin);
	p(buffer);
	if (m == 0x1025544)
	{
		system("/bin/cat /home/user/level5/.pass");
	}
}

int	main(void)
{
	n();
	return (0);
}
