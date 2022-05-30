#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if Big endian. 1 if little endian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c;

	c = (char *) &i;

	return (*c);
}
