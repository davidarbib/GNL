/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:44:41 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 18:02:48 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*ptr;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	ptr = (char *)haystack;
	while (*ptr)
	{
		i = 0;
		while (ptr[i] == needle[i] && needle[i])
			i++;
		if (!needle[i])
			return (ptr);
		ptr++;
	}
	return (NULL);
}
