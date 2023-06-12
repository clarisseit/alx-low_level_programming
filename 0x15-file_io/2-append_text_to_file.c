#include "main.h"

/**
 * append_text_to_file - apends text to file
 * @filename: path to file
 * @text_content: content
 * Return: 1 or -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, my_write, i = 0;

	/* Checks if filename is NULL  and return -1 */
	if (!filename)
		return (-1);
	/* Opens file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	/* If text_content is not empty, append it to file */
	if (text_content)
	{
		/* Counts the number of characters in text_content */
		while (text_content[i])
			i++;
		/* Write text_content to file */
		my_write = write(fd, text_content, i);
		/* Checls if writing to the file failed */
		if (my_write == -1)
			return (-1);
	}
	close(fd);
	return (1);
}
