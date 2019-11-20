/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:46:56 by darbib            #+#    #+#             */
/*   Updated: 2019/11/19 20:05:52 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

/*
 *
on check la static
si elle existe on la copie jusqua \n
on lit le fd
on s'arrete a \n ou si on a rien a lire
on copie le buffer
return
1 : Une ligne a été lue
0 : La fin de fichier a été atteinte
-1 : Une erreur est survenue

gerer les fichiers
redirections
fichiers speciaux (null, random, ...)
*/

static int		ex_error(char *afterendl, int excode)
{
	if (afterendl)
		free(afterendl);
	return (excode);
}

static char		seekcheck(size_t *samechar, char *buf, char **endl, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && buf[i] != '\n')
	{
		if (buf[i] != buf[i + 1])
			*samechar = 0;
		if ((*samechar)++ > 200)
			return (0);
		i++;
	}
	if (buf[i] == '\n')
	{
		*endl = buf + i;
		buf[i] = '\0';
	}
	return (1);
}

static int		retrieve(char **line, char **afterendl, char **endl)
{
	char	*p_ae;
	char	*tmp;
	
	p_ae = *afterendl;
	tmp = *afterendl;
	while (*p_ae && *p_ae != '\n')
		p_ae++;
	if (*p_ae)
	{
		*endl = p_ae;
		*p_ae = '\0'; 
	}
	if (!(*line = ft_strdupfree(*afterendl, 0)))
		return (ex_error(*afterendl, -1));
	if (!(*afterendl = ft_strdupfree(*(endl + 1), 0)))
		return (ex_error(*afterendl, -1));
	free(tmp);
	return (1);
}

static int		read_til_endl(int fd, char **line, char *buf, char **endl)
{
	size_t		n_bytes;
	size_t		samechar;

	samechar = 0;
	n_bytes = 1;
	while (n_bytes > 0 && !*endl)
	{	
		if ((n_bytes = read(fd, buf, BUFFER_SIZE) == -1))
			return (-1);
		buf[n_bytes] = '\0';
		if (!seekcheck(0, buf, endl, n_bytes))
			return (-1);
		if (!(*line = ft_strjoinfree(*line, buf, 1)))
			return (-1);
	}
	return (n_bytes);
}

int				get_next_line(int fd, char **line)
{
	static char	*afterendl;
	char		*endl;
	int			rd_result;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (ex_error(afterendl, -1));
	if (!(*line = ft_strdupfree("", 0)))
		return (ex_error(afterendl, -1));
	endl = NULL;
	if (afterendl)
	{
		if ((retrieve(line, &afterendl, &endl)) == -1)
			return (ex_error(afterendl, -1));
	}
	if (endl)
		return (1);
	if ((rd_result = read_til_endl(fd, line, buf, &endl)) == -1)
		return (-1);
	if (endl && !(afterendl = ft_strdupfree(endl + 1, 0)))
		return (-1);
	if (!rd_result && !endl && !**line)
		return (ex_error(afterendl, 0));
	return (1);
}

int main(int ac, char **av)
{
	char	*line;
	int		gnl;
	int		fd;

	(void)ac;
	(void)av;
	fd = open(av[1], O_RDONLY);
	//fd = 1;
	line = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		printf("gnl value : %d\n", gnl);
		free(line);
	}
	printf("%s\n", line);
	printf("gnl value : %d\n", gnl);
}
