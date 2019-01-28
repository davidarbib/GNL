/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:51:36 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 18:11:38 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*count_dup(char **s_ptr, char c)
{
	size_t	nb_l;
	size_t	i;
	char	*dup;

	while (**s_ptr && **s_ptr == c)
		*s_ptr = *s_ptr + 1;
	nb_l = 0;
	while (*(*s_ptr + nb_l) && *(*s_ptr + nb_l) != c)
		nb_l++;
	if (!(dup = (char *)malloc(sizeof(char) * (nb_l + 1))))
		return (NULL);
	i = 0;
	while (i < nb_l)
	{
		dup[i] = *(*s_ptr + i);
		i++;
	}
	dup[i] = '\0';
	*s_ptr += nb_l;
	return (dup);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	word_n;
	char	**s_tab;
	char	**s_ptr;

	if (!s)
		return (NULL);
	i = 0;
	word_n = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			word_n++;
		i++;
	}
	if (!(s_tab = (char **)malloc(sizeof(char *) * (word_n + 1))))
		return (NULL);
	s_ptr = (char **)&s;
	i = -1;
	while (++i < word_n)
		s_tab[i] = count_dup(s_ptr, c);
	s_tab[i] = NULL;
	return (s_tab);
}
