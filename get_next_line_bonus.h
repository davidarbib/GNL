/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:42:04 by darbib            #+#    #+#             */
/*   Updated: 2019/11/22 13:42:12 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strjoinfree(char const *s1, char const *s2, char clear);
char	*ft_strdupfree(const char *s1, char clear);

#endif
