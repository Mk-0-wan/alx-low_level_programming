#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * read_textfile - read a text file and output its content to the STDOUT_FILENO
 * @filename: pointer to a memory address containing the content of the file.
 * @letters: number of bytes to write to the STDOUT_FILENO
 * Return: number of bytes written
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, i = 0;
	int size_of_read_write = 0, ret = 0;
	char *local_buffer = malloc(letters);

	if (!filename || !local_buffer || !letters) /* check for empty buffers */
		return (0);

	fd = open(filename, O_RDONLY);/* read only mode */
	if (fd == -1)
	{
		free(local_buffer);
		return (0);
	}
	size_of_read_write = read(fd, local_buffer, letters); /* reading file */
	if (size_of_read_write == -1)
	{/* handling read */
		free(local_buffer);
		close(fd);
		return (0);
	}
	size_of_read_write = 0;
	while (local_buffer && local_buffer[i])
		i++;

	size_of_read_write = write(STDOUT_FILENO, local_buffer, i);
	/* write to STDOUT */
	if (size_of_read_write == -1)
	{
		free(local_buffer);
		close(fd);
		return (0);
	}
	ret = size_of_read_write;/* keep record of the last write system call */
	free(local_buffer); /* avoid memory leaks */
	close(fd);
	return ((ssize_t)ret);
}
