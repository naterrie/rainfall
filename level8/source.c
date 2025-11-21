#include <stdio.h>
#include <stdlib.h>

char *service;
char *auth;

int	main(void)
{
	char buffer[128];
	while (1)
	{
		printf("%p, %p\n", auth, service);
		if (fgets(buffer, 128, stdin) == NULL)
			break;

		if (strncmp(buffer, "auth ", 5) == 0)
			auth = malloc(4);

		else if (strncmp(buffer, "reset", 5) == 0)
			free(auth);

		else if (strncmp(buffer, "service", 6) == 0)
			service = strdup(buffer + 7);

		else if (strncmp(buffer, "login", 5) == 0)
		{
			if ((*auth + 32) != NULL)
				system("/bin/cat /home/user/level9/.pass");
			else
				fwrite("Password:\n", 1, 10, stdout);
		}

	}
	return (0);
}
