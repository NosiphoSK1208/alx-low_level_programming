#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates and prints passwords for the crackme5 executable.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char passcode[7], *acode;
	int len = strlen(argv[1]), i, lasting ;

	acode = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	lasting  = (len ^ 59) & 63;
	passcode[0] = acode[lasting ];

	lasting  = 0;
	for (i = 0; i < len; i++)
		lasting  += argv[1][i];
	passcode[1] = acode[(lasting  ^ 79) & 63];

	lasting  = 1;
	for (i = 0; i < len; i++)
		lasting  *= argv[1][i];
	passcode[2] = acode[(lasting  ^ 85) & 63];

	lasting  = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > lasting )
			lasting  = argv[1][i];
	}
	srand(lasting  ^ 14);
	passcode[3] = acode[rand() & 63];

	lasting  = 0;
	for (i = 0; i < len; i++)
		lasting  += (argv[1][i] * argv[1][i]);
	passcode[4] = acode[(lasting  ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		lasting  = rand();
	passcode[5] = acode[(lasting  ^ 229) & 63];

	passcode[6] = '\0';
	printf("%s", passcode);
	return (0);
}
