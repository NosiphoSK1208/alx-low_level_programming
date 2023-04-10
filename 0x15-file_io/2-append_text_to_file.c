#include "main.h"
#include <stdlib.h>

/**
 *append_text_to_file - appends text to the end of a file
 *@filename: name of the file
 *@text_content: NULL terminated string to add to the file
 *
 *Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len, bytes_written;

	if (filename == NULL)
		return (-1);

	/*open the file in append mode, create it if it doesn't exist */
	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0600);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	/*get the length of the string to write */
	for (len = 0; text_content[len] != '\0'; len++)
	;

	/*write the string to the file */
	bytes_written = write(fd, text_content, len);
	close(fd);

	/*return 1 on success, -1 on failure */
	return (bytes_written == len ? 1 : -1);
}
