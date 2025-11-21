#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int language;

void greetuser(char *str)
{
	char lang[64];
	if (language == 1)
		strcpy(lang, "Hyvää päivää ");
	else if (language == 2)
		strcpy(lang, "Goedemiddag! ");
	else if (language == 0)
		strcpy(lang, "Hello ");

	strcat(lang, str);
	puts(lang);
}


int main(int argc, char **argv)
{
	char *lang;
	char buffer[72];

	if (argc == 3)
	{
		memset(buffer, 0, 72);
		strncpy(buffer, argv[1], 40);
		strncpy(&buffer[40], argv[2], 32);
		buffer[71] = '\0';

		lang = getenv("LANG");

		if (strstr(lang, "fi") != NULL)
			language = 1;
		else if (strstr(lang, "nl") != NULL)
			language = 2;
		else
			language = 0;

		greetuser(argv[1]);
	}
	else
		return 1;
	return 0;
}
