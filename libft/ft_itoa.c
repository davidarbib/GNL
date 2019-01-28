/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:48:56 by darbib            #+#    #+#             */
/*   Updated: 2018/12/03 17:52:01 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makezero(void)
{
	char *n_str;

	if (!(n_str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	n_str[0] = '0';
	n_str[1] = '\0';
	return (n_str);
}

static char	*makestr(int d_nb, int sign, int *tab)
{
	char	*n_str;
	size_t	j;

	if (!(n_str = (char *)malloc(sizeof(char) * (d_nb + 1 +
						((sign - 1) * (sign - 1) / 4)))))
		return (NULL);
	d_nb--;
	j = 0;
	if (sign == -1)
	{
		n_str[0] = '-';
		j = 1;
	}
	while (d_nb > -1)
	{
		n_str[j] = (char)(tab[d_nb] + '0');
		d_nb--;
		j++;
	}
	n_str[j] = '\0';
	return (n_str);
}

static int	sign_of(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char		*ft_itoa(int n)
{
	int		tab[11];
	int		i;
	int		sign;

	if (!n)
		return (makezero());
	i = 0;
	if (n == -2147483648)
	{
		tab[0] = 8;
		i = 1;
		n = -214748364;
	}
	sign = sign_of(n);
	n *= sign;
	while (n > 0)
	{
		tab[i] = n % 10;
		n /= 10;
		i++;
	}
	return (makestr(i, sign, tab));
}
