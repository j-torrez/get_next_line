/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:54:08 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/05/29 18:26:47 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Extract a line from stash and return it*/
// Initialize stash with an empty string.
// Initialize with a valid memory address, (use ft_strjoini)
/*Loop continue as long '\n' is not found in Stash.*/
static char	*ft_free(char *stash, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stash, buffer);
	free(stash);
	return (temp);
}

static char	*ft_read_line(int fd, char *stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (stash == NULL)
		stash = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_free(stash, buffer);
	}
	free(buffer);
	return (stash);
}
/*Enough space to store the line, newline character and Null terminator*/

char	*ft_get_line(char *stash)
{
	int		i;
	char	*str;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/* Removes the first line from the string "stash", creates a new string
with the remaining lines, frees the memory of the original "stash"
and return the new string*/

static char	*ft_save_remaining_lines(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
	{
		str[j++] = stash[i++];
	}
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_save_remaining_lines(stash);
	return (line);
}
/*
int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*result;

	result = get_next_line(fd);
	printf("%s", result);
	free(result);


	result = get_next_line(fd);
	printf("%s", result);
	close(fd);
	free(result);
}*/