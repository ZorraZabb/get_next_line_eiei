#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t  ft_strlen(char const *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *tmp;
    int     index;
    int     index2;

    index = 0;
    index2 = 0;
    if (!s1 || !s2)
        return (NULL);
    tmp = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!tmp)
        return (NULL);
    while (s1[index] != '\0')
    {
        tmp[index] = s1[index];
        index++;
    }
    while (s2[index2] != '\0')
    {
        tmp[index] = s2[index2];
        index2++;
        index++;
    }
    tmp[index] = '\0';
    return (tmp);
}

int check_if_n(char *arr)
{
    int i;

    i = 0;
    while(arr[i] != '\0')
    {
        if (arr[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

char *ft_before_n(char *arr)
{
    char *tmp;
    char *tmp2;
    int i;
    int j;

    i = 0;
    j = 0;
    while (arr[i] != '\n')
        i++;
    while (arr[i + 1] != '\0')
    {
        i++;
        j++;
    }
    tmp = (char *) malloc(sizeof(char) * (i + 2));
    tmp2 = (char *) malloc(sizeof(char) * (j + 1));
    i = 0;
    j = 0;
    while (arr[i] != '\n')
    {
        tmp[i] = arr[i];
        i++;
    }
    while (arr[i + 1] != '\0')
    {
        tmp2[j] = arr[i + 1];
        i++;
        j++;
    }
    tmp[i] = '\n';
    tmp[i++] = '\0';
    tmp2[j] = '\0';
    // printf("TMP   = [%s]\n", tmp);
    // printf("TMP02 = [%s]\n", tmp2);
    return (tmp);
}

char *get_next_line(int fd)
{
    int read_num;
    char *line;
    static char *arr;

    line = (char *) malloc(sizeof(char) * 1);
    arr = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!arr)
        return (NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    read_num = 1;
    while (read_num > 0)
    {
        read_num = read(fd, arr, BUFFER_SIZE);
        if (read_num < 0)
        {
            free(arr);
            return (NULL);
        }
        // printf("STRING[%d] = [%s]\n",fd,arr);
        line = ft_strjoin(line,arr);
        // printf("RESULT = [%s]\n",line);
        if (check_if_n(arr))
            break;
    }
    line = ft_before_n(line);
    return(line);
}

int main(void)
{
    int ifd, jfd;
    char    *tmp;
    char    *tmp_02;

    ifd = open("read_file.txt", O_RDONLY);
    jfd = open("text.txt", O_RDONLY);
    tmp = get_next_line(ifd);
    tmp_02 = get_next_line(jfd);

    printf("s01 = [%s]\n", tmp);
    printf("s02 = [%s]\n", tmp_02);

    return (0);
}