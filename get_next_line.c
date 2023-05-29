/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorrez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:49:52 by jtorrez-          #+#    #+#             */
/*   Updated: 2023/05/27 15:56:40 by jtorrez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_all_lines(int fd)
{
	char			*buffer;
	ssize_t			bytes_read;
	static	char	*stash;

	stash = NULL; //Initialize stash with an empty string. 
	if (stash == NULL) 
			stash = ft_strdup(""); //Initialize with a valid memory address, (use ft_strjoin)

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return 0; 

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) //Read return 0 end of file.
	{
    	if(bytes_read == -1) //Return -1, error. 
    	{
			return NULL;
    	}
		stash = ft_strjoin(stash, buffer); 
		buffer[bytes_read] = '\0';
    
	}
	free (buffer);
	return (stash);
}

static char *get_line(char *stash)
{
	static char	*line = NULL; // Initialize line as NULL
	static int	start = 0; // Initialize start as 0
	size_t	len;
	size_t	i;

	char *result = ft_strchr(stash + start, '\n'); // Search for '\n' starting from the start position
	i = 0;
	if (result != NULL)
	{
		len = result - (stash + start); // Calculate the length of the line        
		line = (char *)malloc((len + 1) * sizeof(char)); // Allocate memory for the line  
		if (line != NULL)
		{   
			while (i < len)
			{
				line[i] = stash[start + i]; // Copy each character of the line
				i++;
			}
			line[len] = '\0'; // Add null-termination at the end of the line
		}
		start += len + 1; // Update the start position for the next line
	}
	else
	{
		line = NULL; // Reset line to NULL if no more lines are found
	}
	return line;
	free (line);
}

char *get_next_line(int fd)
{
	char *new_line;
    static char *stash = NULL;

    if (stash == NULL)
        stash = get_all_lines(fd);

    new_line = get_line(stash);
    return new_line;
}

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *result;
    char *line;
	char *final_result;  

   /* result = get_all_lines(fd);
    line = get_line(result);
    printf("%s\n", result);
    printf("****************\n");
    printf("%s\n", line);

    line = get_line(result);
    printf("%s\n", line);

    line = get_line(result);
    printf("%s\n", line);

    line = get_line(result);
    printf("%s\n", line);	*/

	printf("****************\n");
	final_result = get_next_line(fd);
	printf("%s\n", final_result);
	final_result = get_next_line(fd);
	printf("%s\n", final_result);
	final_result = get_next_line(fd);
	printf("%s\n", final_result);
}		
