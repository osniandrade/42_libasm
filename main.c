/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 09:05:02 by ocarlos-          #+#    #+#             */
/*   Updated: 2021/01/01 16:26:04 by ocarlos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

void	ft_test_strlen(char *s1, char *empty_s, char *long_s)
{
	printf("**********FT_STRLEN*********\n\n");
	printf("strlen: %lu\nlibasm: %lu\n\n", strlen(s1), ft_strlen(s1));
	printf("strlen: %lu\nlibasm: %lu\n\n", strlen(empty_s), ft_strlen(empty_s));
	printf("strlen: %lu\nlibasm: %lu\n\n", strlen(long_s), ft_strlen(long_s));
}

void	ft_test_strcmp(char *s1, char *s2, char *empty_s, char *long_s)
{
	printf("**********FT_STRCMP*********\n\n");
	printf("strcmp: %i\nlibasm: %i\n\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	printf("strcmp: %i\nlibasm: %i\n\n", strcmp(empty_s, s1), ft_strcmp(empty_s, s1));
	printf("strcmp: %i\nlibasm: %i\n\n", strcmp(long_s, s2), ft_strcmp(long_s, s2));
	printf("strcmp: %i\nlibasm: %i\n\n", strcmp(s2, s2), ft_strcmp(s2, s2));
}

void	ft_test_strcpy(char *s1, char *empty_s, char *long_s)
{
	char d1[50];
	char d2[50];

	printf("**********FT_STRCPY*********\n\n");
	strcpy(d1, s1); 
	ft_strcpy(d2, s1);
	printf("strcpy: %s\nlibasm: %s\n\n", d1, d2);
	strcpy(d1, empty_s); 
	ft_strcpy(d2, empty_s);
	printf("strcpy: %s\nlibasm: %s\n\n", d1, d2);
	strcpy(d1, long_s); 
	ft_strcpy(d2, long_s);
	printf("strcpy: %s\nlibasm: %s\n\n", d1, d2);
}

void	ft_test_strdup(char *s1, char *empty_s, char *long_s)
{
	char *d1;
	char *d2;

	printf("**********FT_STRDUP*********\n\n");
	d1 = strdup(s1);
	d2 = ft_strdup(s1);
	printf("strdup: %s\nlibasm: %s\n\n", d1, d2);
	free(d1);
	free(d2);
	d1 = strdup(empty_s);
	d2 = ft_strdup(empty_s);
	printf("strdup: %s\nlibasm: %s\n\n", d1, d2);
	free(d1);
	free(d2);
	d1 = strdup(long_s);
	d2 = ft_strdup(long_s);
	printf("strdup: %s\nlibasm: %s\n\n", d1, d2);
	free(d1);
	free(d2);
}

void	ft_test_write(char *s2)
{
	printf("**********FT_WRITE**********\n\n");
	printf("write:  %zi\n", write(1, s2, 9));
	printf("libasm: %zi\n\n", ft_write(1, s2, 9));
	write(42, s2, 14);
	printf("write:  %zi, error %s\n", write(42, s2, 14), strerror(errno));
	printf("libasm: %zi, error %s\n\n", ft_write(42, s2, 14), strerror(errno));
}

void	ft_test_read()
{
	char	*buf1;
	char	*buf2;
	int		fd;

	buf1 = calloc(500, sizeof(char));
	buf2 = calloc(500, sizeof(char));
	printf("***********FT_READ**********\n\n");
	fd = open("test", O_RDONLY);
	printf("read:   %zi, %s\n", read(fd, buf1, 5), buf1);
	fd = open("test", O_RDONLY);
	printf("libasm: %zi, %s\n\n", ft_read(fd, buf2, 5), buf2);
	read(-7, buf1, 7);
	printf("read:   %zi, error: %s\n", read(-7, buf1, 7), strerror(errno));
	printf("libasm: %zi, error: %s\n\n", ft_read(-7, buf1, 7), strerror(errno));
}

int		main(void)
{
	char	*s1;
	char	*s2;
	char	*empty_s;
	char	*long_s;

	s1 = "The cake is a lie";
	s2 = "Companion Cube";
	empty_s = "";
	long_s = ";;'Aperture Science';; we do what we must because we can";

	ft_test_strlen(s1, empty_s, long_s);
	ft_test_strcmp(s1, s2, empty_s, long_s);
	ft_test_strcpy(s1, empty_s, long_s);
	ft_test_strdup(s1, empty_s, long_s);
	ft_test_write(s2);
	ft_test_read();
	return (0);
}