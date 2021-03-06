/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:16:52 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 17:57:40 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	char			*ps1;

	ps1 = s1;
	while (*ps1)
		ps1++;
	i = 0;
	while (s2[i] && i < n)
	{
		ps1[i] = s2[i];
		i++;
	}
	ps1[i] = '\0';
	return (s1);
}
