#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("get_next_line.h", O_RDWR, 0777);
	int fd1 = open("a.txt", O_RDWR, 0777);
	int fd2 = open("s.txt", O_RDWR, 0777);
	char *result = get_next_line(fd);
	char *result1 = get_next_line(fd1);
	char *result2 = get_next_line(fd2);
	while (result || result1 || result2)
	{
		if(result != NULL)
		{
			printf("%s", result);
			free(result);
			result = get_next_line(fd);
		}
		if(result1 != NULL)
		{
			printf("%s", result1);
			free(result1);
			result1 = get_next_line(fd1);
		}
		if(result2 != NULL)
		{
			printf("%s", result2);
			free(result2);
			result2= get_next_line(fd +2);
		}
	}
	system("leaks a.out");
}
