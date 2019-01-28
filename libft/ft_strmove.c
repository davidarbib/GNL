/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:18:56 by darbib            #+#    #+#             */
/*   Updated: 2019/01/25 17:59:25 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char **s1)
{
	char	*dup;
	int		i;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + 1))))
		return (NULL);
	i = 0;
	while ((*s1)[i])
	{
		dup[i] = (*s1)[i];
		i++;
	}
	dup[i] = '\0';
	ft_strdel(s1);
	return (dup);
}
