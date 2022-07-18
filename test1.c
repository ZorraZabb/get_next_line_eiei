#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42 test.c -o test
size_t ft_strlen(char *arr)
{
    int i;

    i = 0;
    while (*(arr + i) != '\0')
    {
        i++;
    }
    return (i);
}

int check_if_n(char *arr)
{
    int i;

    i = 0;
    while(*(arr + i) != '\0')
    {
        if (*(arr + i) == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *store_first_line(char *arr)
{
    size_t i;
    char    *stored;
    
    i = 0;
    if (!check_if_n(arr))
    {
        printf("IN THE CON = [%s]\n",arr);
        return (arr);
    }
    while(*(arr + i) != '\n')
        i++;
    stored = (char *)malloc(sizeof(char)*(i + 1));
    if (!stored)
        return (NULL);
    i = 0;
    while(*(arr + i) != '\n')
    {
        *(stored + i) = *(arr + i);
        i++;
    }
    *(stored + i) = '\n';
    return (stored);
}

char *get_next_line(int fd)
{
    int     read_num;
    char    *line;
    static char    *arr;
    arr = (char *) malloc(sizeof(char)*(BUFFER_SIZE + 1));
    if (!arr)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    read_num = read(fd, arr, BUFFER_SIZE);
    printf("GET = [%s]\n",arr);
    line = store_first_line(arr);
    printf("LINE = [%s]\n", line);
    // printf("GET = [%s]\n",arr);
    printf("D = [%d]\n",read_num);
    return(line);
}

int main(void)
{
    int     ifd, jfd;
    char    *tmp;
    char    *tmp_02;

    ifd = open("read_file.txt", O_RDONLY);
    jfd = open("text.txt", O_RDONLY);
    tmp = get_next_line(ifd);
    tmp_02 = get_next_line(jfd);

    printf("-------------------------------\n");
    printf("STRING_01 = [\n");
    printf("%s\n]\n",tmp);
    printf("STRING_02 = [\n");
    printf("%s\n]\n",tmp_02);

    printf("TEST = [%s]\n",store_first_line(tmp));
    printf("TEST = [%s]\n",store_first_line(tmp_02));

    return (0);
}