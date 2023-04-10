#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 1024

/**
 *main - copies the content of a file to another file
 *@ac: argument count
 *@av: argument vector
 *
 *Return: 0 on success, or an exit code on failure
 */
int main(int ac, char **av)
{
	int from_fd, to_fd, bytes_read, bytes_written;
	char buf[BUF_SIZE];
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	from_fd = open(av[1], O_RDONLY);
	if (from_fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	to_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (to_fd == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);

	while ((bytes_read = read(from_fd, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(to_fd, buf, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	}

	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);

	if (close(from_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd), exit(100);

	if (close(to_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd), exit(100);

	return (0);
}
