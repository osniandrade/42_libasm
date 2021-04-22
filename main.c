#include "libasm.h"

void	ft_ck_read()
{
	int		fd;
	char	buff[100];
	char	show[100];
	ssize_t	ret;

	// fd = open("test.txt", O_RDONLY);
	// ret = read(fd, buff, 29); 
	// printf("`%s`:%ld\n", buff, ret);
	// close(fd);
	// fd = open("test.txt", O_RDONLY);
	// ret = ft_read(fd, buff, 29); 
	// printf("`%s`:%ld\n", buff, ret);
	// close(fd);

	printf("ft_read:\n");
	printf("	[1] 'open(\"main.c\", O_RDONLY)' '' '0'\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buff, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, buff, 10);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	printf("	[2] 'open(\"test.txt\", O_RDONLY)' '' '50'\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, buff, 50);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 50));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, buff, 50);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 50));
	close(fd);
	printf("	[3] 'open(\"dontexist\", O_RDONLY)' '' '10'\n");
	fd = open("dontexist", O_RDONLY);
	ret = read(fd, buff, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	fd = open("dontexist", O_RDONLY);
	ret = ft_read(fd, buff, 10);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	printf("	[4] 'open(\"test.txt\", O_RDONLY)' 'NULL' '10'\n");
	fd = open("test.txt", O_RDONLY);
	ret = read(fd, NULL, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	ret = ft_read(fd, NULL, 10);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd\n", ret);
	close(fd);
	printf("	[5] '42' '' '10'\n");
	ret = read(42, buff, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	ret = ft_read(42, buff, 10);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
	printf("	[3] 'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\n");
	ret = read(fd, buff, 10);
	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	ret = ft_read(fd, buff, 10);
	printf("		\x1b[34m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buff, 10));
	close(fd);
	remove("empty_file");

}

int     main(int argc, char *argv[])
{
	ft_ck_read();
}