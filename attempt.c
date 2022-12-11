#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char *Buf;
	fd = open("deneme.txt", O_CREAT | O_RDWR, 0777);

	write(fd, "hello world", 11);
	close(fd);
	fd = open("deneme.txt", O_RDWR, 0777);
	read(fd, Buf, 5);
	printf("%s\n", Buf);
	read(fd, Buf, 5);
	printf("%s", Buf);
}
