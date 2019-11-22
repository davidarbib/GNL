/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:46:56 by darbib            #+#    #+#             */
/*   Updated: 2019/11/22 13:28:44 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

static int		get_out(char *afterendl, char *buf, int excode)
{
	free(afterendl);
	free(buf);
	return (excode);
}

static char		seekcheck(size_t *samechar, char *buf, char **endl, int n)
{
	int	i;

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
		return (get_out(*afterendl, NULL, -1));
	if (*endl)
	{
		if (!(*afterendl = ft_strdupfree(*endl + 1, 0)))
			return (get_out(*afterendl, NULL, -1));
	}
	else
		*afterendl = NULL;
	free(tmp);
	return (1);
}

static int		read_til_endl(int fd, char **line, char *buf, char **endl)
{
	int		n_bytes;
	size_t	samechar;

	samechar = 0;
	n_bytes = 1;
	while (n_bytes > 0 && !*endl)
	{
		if ((n_bytes = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		buf[n_bytes] = '\0';
		if (!seekcheck(&samechar, buf, endl, n_bytes))
			return (-1);
		if (!(*line = ft_strjoinfree(*line, buf, 1)))
			return (-1);
	}
	return (n_bytes);
}

int				get_next_line(int fd, char **line)
{
	char		*endl;
	int			rd_result;
	char		*buf;
	static char	*afterendl;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (get_out(afterendl, NULL, -1));
	endl = NULL;
	*line = NULL;
	if (afterendl && (retrieve(line, &afterendl, &endl) == -1))
		return (get_out(afterendl, NULL, -1));
	if (endl)
		return (1);
	if (!(buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if (!*line && !(*line = ft_strdupfree("", 0)))
		return (get_out(afterendl, NULL, -1));
	if ((rd_result = read_til_endl(fd, line, buf, &endl)) == -1)
		return (get_out(afterendl, buf, -1));
	if (endl && !(afterendl = ft_strdupfree(endl + 1, 0)))
		return (get_out(afterendl, buf, -1));
	if (rd_result < BUFFER_SIZE && !endl)
		return (get_out(afterendl, buf, 0));
	return (get_out(NULL, buf, 1));
}
