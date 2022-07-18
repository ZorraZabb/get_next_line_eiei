#ifdef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

size_t ft_strlen(char const *str);
char *ft_strjoin(char const *s1, char const *s2);
int check_if_n(char *arr);
char *ft_before_n(char *arr);
char *get_next_line(int fd);

#endif