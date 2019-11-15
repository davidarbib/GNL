/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:21:28 by darbib            #+#    #+#             */
/*   Updated: 2019/11/15 19:36:00 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	n;
	size_t	i;

	if (!(sub_s = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	n = ft_strlen(s);
	i = 0;
	while (i < len && start < n)
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = 0;
	return (sub_s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void *mem;
	size_t i;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	if (!(mem = malloc(count * size)))
		return (NULL);
	i = 0;
	while (i < count * size + 1)
		((unsigned char *)mem)[i++] = 0;
	return (mem);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*s_out;

	len = ft_strlen(s1);
	if (!(s_out = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)s_out)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	s_out[len] = 0;
	return (s_out);
}

void	*ft_realloc(void *mem, int size_in, int nb)
{
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}
