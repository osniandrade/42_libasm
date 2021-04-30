#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

ssize_t ft_read(int fd, void *buf, size_t nbyte);
size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    ft_strcpy(char *dst, const char *src);
char    *ft_strdup(const char *s);
size_t  ft_write(int fd, const void *buf, size_t count);

#endif