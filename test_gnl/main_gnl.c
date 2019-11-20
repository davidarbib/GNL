#include "../gnl2/get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int				get_next_line(int fd, char **line);

int main(int ac, char **av)
{
	char	*line;
	int		gnl;
	int		fd;

	(void)ac;
	(void)av;
	//fd = open(av[1], O_RDONLY);
	//fd = 1;
	fd = 0;
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	//while (1) {};
}
