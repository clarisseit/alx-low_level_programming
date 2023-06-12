#include "main.h"

/**
 * create_file - append to file
 * @filename: path to file
 * @text_content: content
 * Return: chars read
 */

int create_file(const char *filename, char *text_content)
{
	int fd, my_write, i = 0;

	/* Check if filename is NULL and return -1 */
	if (!filename)
		return (-1);
	/*
	 * Open file for write only, create it if it doesn't exist
	 * Truncate to zero length if it exists
	 * 0600, Sets file permissions to rw- --- ---, read & write for owner only
	 */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	/* If text_content is not empty, write it to file */
	if (text_content)
	{
		/* Counts number of characters in text_content */
		while (text_content[i])
			i++;
		/* Writes text_content to file */
		my_write = write(fd, text_content, i);
		if (my_write == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
