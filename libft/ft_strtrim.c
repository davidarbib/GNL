/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:24:22 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 18:04:30 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpt(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	if (i < -1)
		i = -1;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	left;
	int		i;

	if (!s)
		return (NULL);
	left = 0;
	while (s[left] && (s[left] == ' ' || s[left] == '\n' || s[left] == '\t'))
		left++;
	i = cpt(s + left);
	if (!(trim = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	trim[i + 1] = '\0';
	while (i > -1)
	{
		trim[i] = s[i + left];
		i--;
	}
	return (trim);
}
