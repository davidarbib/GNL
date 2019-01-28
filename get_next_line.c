/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:51:59 by darbib            #+#    #+#             */
/*   Updated: 2019/01/28 17:58:31 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

static int	rd_join_sk(int fd, char **line, char **p_eol)
{
	char	*buf;
	int		bytes_rd;

	bytes_rd = 1;
	while (!(*p_eol) && bytes_rd)
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		if ((bytes_rd = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[bytes_rd] = '\0';
		*line = ft_strjoinfree(line, &buf, 3);
		*p_eol = ft_strchr(*line, '\n');
	}
	return (bytes_rd);
}

int			get_next_line(int fd, char **line)
{
	static char *since_eol;
	char		*p_eol;
	int			bytes_rd;

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	p_eol = NULL;
	*line = NULL;
	if (since_eol)
	{
		*line = ft_strmove(&since_eol);
		p_eol = ft_strchr(*line, '\n');
	}
	bytes_rd = rd_join_sk(fd, line, &p_eol);
	if ((bytes_rd) == -1)
		return (-1);
	if (p_eol)
	{
		(*line)[p_eol - *line] = '\0';
		since_eol = ft_strdup(p_eol + 1);
	}
	if (!(**line) && !since_eol)
		return (0);
	return (1);
}
