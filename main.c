#include "libasm.h"

void	ft_ck_read(char *file, int chars, int flag)
{
	int		fd;
	char	buff1[100];
	char	buff2[100];
	ssize_t	ret1, ret2;

	if (flag == 1)
	{
		fd = open(file, O_RDONLY);
		ret1 = read(fd, buff1, chars);
		close(fd);
		fd = open(file, O_RDONLY);
		ret2 = ft_read(fd, buff2, chars);
	}
	if (flag == 2)
	{
		fd = open(file, O_RDONLY);
		ret1 = read(fd, NULL, chars);
		close(fd);
		fd = open(file, O_RDONLY);
		ret2 = ft_read(fd, NULL, chars);
	}
	if (flag == 3)
	{
		fd = 42;
		ret1 = read(fd, buff1, chars);
		close(fd);
		fd = 42;
		ret2 = ft_read(fd, buff2, chars);
	}
	if (flag == 4)
	{
		fd = open("empty", O_RDONLY | O_TRUNC | O_CREAT, 0777);
		ret1 = read(fd, buff1, chars);
		close(fd);
		fd = open("empty", O_RDONLY | O_TRUNC | O_CREAT, 0777);
		ret2 = ft_read(fd, buff2, chars);
	}
	close(fd);
	if (flag == 4)
		remove("empty");

	if (ret1 == ret2 && strncmp(buff1, buff2, chars) == 0)
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
}

void	ft_ck_strlen(char *src)
{
	int		a;
	int		b;

	a = strlen(src);
	b = ft_strlen(src);
	if (a == b)
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
}

void	ft_ck_strcmp(char *src1, char *src2)
{
	int		a;
	int		b;

	a = strcmp(src1, src2);
	b = ft_strcmp(src1, src2);
	printf("%d\n", a);
	printf("%d\n", b);
	if (a == b)
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
}

void	ft_ck_strcpy(char *src)
{
	char	dst1[100];
	char	dst2[100];

	bzero(dst1, 100);
	bzero(dst2, 100);
	strcpy(dst1, src);
	ft_strcpy(dst2, src);
	if (!strcmp(dst1, dst2))
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
}

void	ft_ck_strdup(char *src)
{
	char	*dst1;
	char	*dst2;

	dst1 = strdup(src);
	dst2 = ft_strdup(src);
	if (!strcmp(dst1, dst2))
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
	//free(dst1);
	//free(dst2);
}

void	ft_ck_write(char *src, int c)
{
	size_t	ret1, ret2;

	ret1 = ft_write(STDOUT_FILENO, src, c);
	printf("\n");
	ret2 = write(STDOUT_FILENO, src, c);
	printf("\n");
	if (ret1 == ret2)
		printf("	[OK]\n");
	else
		printf("	[NOT OK AT ALL]\n");
}

int     main(int argc, char *argv[])
{
	printf("ft_read:\n");
	ft_ck_read("test.txt", 10, 1);
	ft_ck_read("test.txt", 50, 1);
	ft_ck_read("missingfile", 10, 1);
	ft_ck_read("test.txt", 10, 2);
	ft_ck_read("invalid_fd", 10, 3);
	ft_ck_read("empty", 10, 4);
	printf("\n");

	printf("ft_strlen:\n");
	ft_ck_strlen("");
	ft_ck_strlen("heart of gold");
	ft_ck_strlen("01189998819991197253");
	//ft_ck_strlen(NULL);
	printf("\n");

	printf("ft_strcmp:\n");
	ft_ck_strcmp("","");
	ft_ck_strcmp("stringcompare","stringcompare");
	ft_ck_strcmp("stringcompare","");
	ft_ck_strcmp("","stringcompare");
	ft_ck_strcmp("123456","123456");
	printf("\n");
	
	printf("ft_strcpy:\n");
	ft_ck_strcpy("");
	ft_ck_strcpy("01189997253");
	ft_ck_strcpy("adasblestaslbiustous");
	//ft_ck_strcpy(NULL);
	printf("\n");

	printf("ft_strdup:\n");
	ft_ck_strdup("");
	ft_ck_strdup("teste");
	ft_ck_strdup("123456789");
	ft_ck_strdup("superbolinhovamotestarotamanho");
	printf("\n");

	printf("ft_write:\n");
	ft_ck_write("teste", 5);
	ft_ck_write("super bolinho", 10);
	ft_ck_write("super bolinho", 20);
	ft_ck_write("", 10);
	ft_ck_write("", 0);
	printf("\n");
}