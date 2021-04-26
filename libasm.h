#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

ssize_t ft_read(int fd, void *buf, size_t nbyte);
size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);

#endif