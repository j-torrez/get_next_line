/*
    open: int open(const char *pathname, int flags)
    read: size_t read (int fd, void *buf, size_t count)
*/

#include "get_next_line.h"

 char    *get_next_line(int fd)
{
    char        buf[BUFFER_SIZE];
    static char *stash;
    char        *line;
    ssize_t     bytes_read;
    size_t      i;
    size_t      count; 

    
    i = 0;
    count = 20;
    bytes_read = read(fd, buf, count);
    if (fd == -1)
        return NULL;
    if (bytes_read == 0)
        return NULL;
    buf[bytes_read] = '\0'; 

    stash = ft_strdup(buf);
    return stash;
    
}

int main(void)
{
    int fd = open("/nfs/homes/jtorrez-/Documents/get_next_line/text", O_RDONLY);
    char *result; 

    result = get_next_line(fd);
    printf("%s", result);
}


/*
int main(void)
{
    int fd = open("/nfs/homes/jtorrez-/Documents/get_next_line/text", O_RDONLY);
    char buf[10];
    size_t nbr_bytes;

    if (fd == -1)
    {
        printf("There has been an error trying to open the file\n");
    }
    else
    {
        nbr_bytes = read(fd, buf, 5);
        if (nbr_bytes == 0)
        {
            printf("File is empty\n");
        }
        else
        {
            printf("Character is: %d, Content: %s\n", (int)nbr_bytes, buf);
        }
        
    }
}   */