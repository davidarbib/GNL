#include "../gnl2/get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	char	*line;
	int		gnl;
	int		fd;

	(void)ac;
	(void)av;
	//fd = 1;
	//fd = 0;
	fd = open(av[1], O_RDONLY);
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("ret = %d  %s\n", gnl, line);
		free(line);
	}
	printf("ret = %d, %s\n", gnl, line);
	free(line);
	close(fd);
}
