/*
    open: int open(const char *pathname, int flags)
    read: size_t read (int fd, void *buf, size_t count)
*/
/*
#include "get_next_line.h"

 char    *get_next_line(int fd)
{
    char        buf[BUFFER_SIZE];
    static char *stash;
    char        *line;
    ssize_t     bytes_read;
    size_t      i;
    size_t      count;
    char    *str2;  

    
    i = 0;
    count = 5;
    bytes_read = read(fd, buf, count);
    if (fd == -1)
        return NULL;
    if (bytes_read == 0)
        return NULL;
   buf[bytes_read] = '\0'; 

    stash = ft_strdup(buf);

    while (ft_strchr(stash, '\n')!= NULL)
    {
        read(fd, buf, count);
        stash = ft_strjoin(buf, stash);
    }
    buf[bytes_read] = '\0'; 
    return stash;
  
}

int main(void)
{
    int fd = open("/nfs/homes/jtorrez-/Documents/get_next_line/text", O_RDONLY);
    char *result;
    char *result1;

    result = get_next_line(fd);
    printf("%s\n", result);

    result1 = ft_strchr(result, '\n');
    if (result1 != NULL)
    {
        printf("CHARACTER FOUND\n");
    }
    else 
    {
        printf("CHARACTER NOT FOUND\n");
    }
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