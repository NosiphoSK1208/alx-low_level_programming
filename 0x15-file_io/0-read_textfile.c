#include "main.h"
#include <stdlib.h>

/**
 *read_textfile - Read text file and print to STDOUT.
 *@filename: Text file being read.
 *@letters: Number of letters to be read.
 *
 *Return: Actual number of bytes read and printed on success.
 *        0 if function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);

	return (w);
}
