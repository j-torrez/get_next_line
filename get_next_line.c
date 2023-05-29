#include "get_next_line.h"

/* Extract a line from stash and return it*/

static char	*ft_read_first_line(int fd, char *stash)
{
	char			*buffer;
	ssize_t			bytes_read;

	stash = NULL; //Initialize stash with an empty string. 
	if (stash == NULL) 
			stash = ft_strdup(""); //Initialize with a valid memory address, (use ft_strjoin)

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return 0; 

    bytes_read = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes_read > 0) //Loop continue as long '\n' is not found in Stash. 
	{
        bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read == -1) //Return -1, error. 
    	    {
                free (buffer);
                return (NULL);
    	    }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
	}
	free (buffer);
	return (stash);
}
/* Removes the first line from the string "stash", creates a new string
with the remaining lines, frees the memory of the original "stash"
and return the new string*/
static char *ft_save_remaining_lines(char *stash)
{
    int i;
    int j;
    char    *str;

    i = 0; 
    while (stash[i] != '\0' && stash[i] != '\0')
        i++;
    if (stash[i] == '\0')
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
        str[j + i] = stash[i];
        i++;
        j++;
    }
    str[j] = '\0';
    free(stash);
    return (str);
}

char    *get_next_line(int fd)
{
    char *line;
    static char *stash; 

    if (fd < 0)
        return 0; 
    stash = ft_read_first_line(fd, stash);
    if (!stash)
        return (NULL);
    line = ft_display_line(stash);
    stash = ft_save_remaining_lines(stash);
    return (line);
}

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *result;

    result = get_next_line(fd);
    printf("%s", result);
    result = get_next_line(fd);
    printf("%s", result);


}   