#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("hh.txt", O_RDWR);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("\n*****************************************\n");
		(printf("%s", line));
		printf("\n*****************************************\n");
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}