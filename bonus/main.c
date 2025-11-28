#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;
		int i = 0;

    start = clock();
	int fd = open("almoharaf.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nrun time: %fs\n", cpu_time_used);

    return 0;
}
