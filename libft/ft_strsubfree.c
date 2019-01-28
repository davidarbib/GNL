/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:21:23 by darbib            #+#    #+#             */
/*   Updated: 2019/01/16 16:35:18 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strsubfree(char const *s, unsigned int start, size_t len, int f)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[len] = '\0';
	if (f)
		free((void *)s);
	return (sub);
}
