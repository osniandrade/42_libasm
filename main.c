#include "libasm.h"

void	ft_ck_read()
{
	int		fd;
	char	buff[100];
	char	show[100];
	ssize_t	ret;

	printf("ft_read:\n");
	printf("	1   'open(\"test.txt\", O_RDONLY)' -> 10 chars\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buff, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, buff, 10);
	printf("		<libasm.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);

	printf("	2   'open(\"test.txt\", O_RDONLY)' -> 50 chars\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buff, 50);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buff, 50));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, buff, 50);
	printf("		<libasm.h>  %zd - %s\n", ret, strncpy(show, buff, 50));
	close(fd);

	printf("	3   'open(\"missingfile\", O_RDONLY)' -> 10 chars\n");
	fd = open("missingfile", O_RDONLY);
	ret = read(fd, buff, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	fd = open("missingfile", O_RDONLY);
	ret = ft_read(fd, buff, 10);
	printf("		<libasm.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);

	printf("	4   'open(\"test.txt\", O_RDONLY)' -> null buffer, 10 chars\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		<unistd.h>  %zd\n", ret);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		<libasm.h>  %zd\n", ret);
	close(fd);

	printf("	5   'inexistent fd'\n");
	ret = read(42, buff, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	ret = ft_read(42, buff, 10);
	printf("		<libasm.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);

	fd = open("empty", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	6   'open(\"empty\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' -> 10 chars\n");
	ret = read(fd, buff, 10);
	printf("		<unistd.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	ret = ft_read(fd, buff, 10);
	printf("		<libasm.h>  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	remove("empty");

	printf("\n\n");
}

void	ft_ck_strlen()
{
	// char *p;

	// p = NULL;
	printf("ft_strlen:\n");

	printf("        1   ''\n");
	printf("            <string.h> %lu\n", strlen(""));
	printf("            <libasm.h> %lu\n", ft_strlen(""));

	printf("        2   '        '\n");
	printf("            <string.h> %lu\n", strlen("        "));
	printf("            <libasm.h> %lu\n", ft_strlen("        "));

	printf("        3   '35184353321'\n");
	printf("            <string.h> %lu\n", strlen("35184353321"));
	printf("            <libasm.h> %lu\n", ft_strlen("35184353321"));

	//printf("        4   NULL\n");
	//printf("            <string.h> %lu\n", strlen(p));
	//printf("            <libasm.h> %d\n", ft_strlen(p));
	printf("\n\n");
}

void	ft_ck_strcmp()
{
	printf("ft_strcmp:\n");

	printf("		1	'' <-> ''\n");
	printf("			<string.h> %d\n", strcmp("", ""));
	printf("			<libasm.h> %d\n", ft_strcmp("", ""));

	printf("		2	'deepthought' <-> 'deepthought'\n");
	printf("			<string.h> %d\n", strcmp("deepthought", "deepthought"));
	printf("			<libasm.h> %d\n", ft_strcmp("deepthought", "deepthought"));

	printf("		3	'' <-> 'deepthought'\n");
	printf("			<string.h> %d\n", strcmp("", "deepthought"));
	printf("			<libasm.h> %d\n", ft_strcmp("", "deepthought"));

	printf("		4	'deepthought' <-> ''\n");
	printf("			<string.h> %d\n", strcmp("deepthought", ""));
	printf("			<libasm.h> %d\n", ft_strcmp("deepthought", ""));

	printf("		5	'deepthought' <-> 'deepthink'\n");
	printf("			<string.h> %d\n", strcmp("deepthought", "deepthink"));
	printf("			<libasm.h> %d\n", ft_strcmp("deepthought", "deepthink"));

	//printf("		6	'42' <-> NULL\n");
	//printf("			<string.h> %d\n", strcmp("42", NULL));
	//printf("			<libasm.h> %d\n", ft_strcmp("42", NULL));

	printf("\n\n");
}

int     main(int argc, char *argv[])
{
	//ft_ck_read();
	//ft_ck_strlen();
	ft_ck_strcmp();
}