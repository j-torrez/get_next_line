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

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *result;
    char *line;
	char *final_result;  

    result = get_all_lines(fd);
    printf("%s\n", result);
}		
