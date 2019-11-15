/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:46:56 by darbib            #+#    #+#             */
/*   Updated: 2019/11/15 19:55:57 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

int		retrieve(char **line, char **afterendl)
{
	size_t	i;
	char	*tmp;
	
	if (!*afterendl)
		return (0);
	i = 0;
	if (!(*line = ft_calloc(ft_strlen(*afterendl) + 1, sizeof(char))))
		return (-1);
	while ((*afterendl)[i] && (*afterendl)[i] != '\n')
	{
		(*line)[i] = (*afterendl)[i];
		i++;
	}
	tmp = *afterendl;
	*afterendl = ft_strdup(*afterendl + i + 1);
	free(tmp);
	if (!(*afterendl))
		return (-1);
	return (i);
}

int		read_til_endl(int fd, char **line)
{	
	char	*endl;
	char	buf[BUFFER_SIZE + 1];
	size_t	samechar;
	size_t	i;
	size_t	n_bytes;

	endl = NULL;
	buf[BUFFER_SIZE] = '\0';
	samechar = 0;
	while (!endl && n_bytes)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		i = 0;
		while (buf[i] && buf[i] != '\n')
			i++;
		if (buf[i])
			endl = buf + i;
		*line = ft_realloc(*line, ft_strlen(*line), i);
		if (samechar++ > 200)
			return (-1);
	}
	return (n_bytes);
}

int		get_next_line(int fd, char **line)
{
	static char	*afterendl;
	(void)fd;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	afterendl = ft_strdup("\n");
	retrieve(line, &afterendl);
	printf("%s\n", *line);
	printf("%s\n", afterendl);
	return (1);
}

int main()
{
	char *line;

	get_next_line(0, &line); 
}
