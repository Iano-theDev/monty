#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - The entry point of the program
 * @argc: The argument count
 * @argv: The argument array
 *
 * Return: 0 on Success
 */
int main(int argc, char **argv)
{

	FILE *fp;

	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	run(fp);

	fclose(fp);

	return (0);
}
