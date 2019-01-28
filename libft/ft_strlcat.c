/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:58:22 by darbib            #+#    #+#             */
/*   Updated: 2018/11/22 14:42:00 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int				i;
	size_t			size_dst;
	char			*pdst;

	pdst = dst;
	while (*pdst)
		pdst++;
	i = 0;
	size_dst = ft_strlen(dst);
	while (src[i] && i < (int)size - (int)size_dst - 1)
	{
		pdst[i] = src[i];
		i++;
	}
	pdst[i] = '\0';
	if (size < size_dst)
		return (size + ft_strlen(src));
	return (size_dst + ft_strlen(src));
}
