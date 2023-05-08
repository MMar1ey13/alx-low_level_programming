#include "main.h"
/**
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to create.
 * @text_content: A pointer to a string to write to the file.
 *
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
	{
	if (filename == NULL)
	{
	return (-1);
	}

	int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (file == -1)
	{
	return (-1);
	}

	if (text_content != NULL)
	{
	ssize_t len = strlen(text_content);
	ssize_t bytesWritten = write(file, text_content, len);

	if (bytesWritten != len)
	{
	close(file);
	return (-1);
	}
	}

	close(file);
	return (1);
}
