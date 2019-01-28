/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <darbib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:01:38 by darbib            #+#    #+#             */
/*   Updated: 2019/01/25 18:26:43 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	maybe_free(char **p_s1, char **p_s2, size_t s_to_free)
{
	if (s_to_free == 1)
		ft_strdel(p_s1);
	if (s_to_free == 2)
		ft_strdel(p_s2);
	if (s_to_free == 3)
	{
		ft_strdel(p_s1);
		ft_strdel(p_s2);
	}
}

static void	justjoin(char **join, char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		(*join)[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		(*join)[i + j] = s2[j];
		j++;
	}
	(*join)[i + j] = '\0';
}

char		*ft_strjoinfree(char **p_s1, char **p_s2, size_t s_to_free)
{
	char *join;

	if (!(*p_s1) && !(*p_s2))
		return (NULL);
	if (!(*p_s1))
	{
		if (s_to_free == 2 || s_to_free == 3)
			return (ft_strmove(p_s2));
		return (ft_strdup(*p_s2));
	}
	if (!(*p_s2))
	{
		if (s_to_free == 1 || s_to_free == 3)
			return (ft_strmove((p_s1)));
		return (ft_strdup(*p_s1));
	}
	if (!(join = (char *)malloc(sizeof(char) *
								(ft_strlen(*p_s1) + ft_strlen(*p_s2) + 1))))
		return (NULL);
	justjoin(&join, *p_s1, *p_s2);
	maybe_free(p_s1, p_s2, s_to_free);
	return (join);
}
