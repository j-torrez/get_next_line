#include "get_next_line.h"

char *get_next(int fd)
{

char *buffer;
char *temp_buffer;
ssize_t bytes_read;

bytes_read = 1;
while (bytes_read > 0) //Read return 0 end of file.
{
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if(bytes_read == -1) //Return -1, error. 
        return 0;
    if(bytes_read < BUFFER_SIZE) //This mean that there are less character in file than BUFFERSIZE
    {
        buffer = (char *)malloc(((BUFFER_SIZE - bytes_read) + 1) * sizeof(char));
    }
    else
    {
        buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    }
    if (!buffer)
        return 0; 
    buffer[bytes_read] = '\0';
}
return buffer;

}

int main(void)
{
    int fd = open("/nfs/homes/jtorrez-/Documents/get_next_line/text", O_RDONLY);
    char *result;

    result = get_next(fd);
    printf("%s\n", result);
}