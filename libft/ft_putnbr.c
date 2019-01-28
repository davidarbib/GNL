/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:48:31 by darbib            #+#    #+#             */
/*   Updated: 2018/11/30 15:23:32 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_of(int n)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	return (sign);
}

void		ft_putnbr(int n)
{
	int		tab[11];
	int		i;

	i = 0;
	if (!n)
		ft_putchar('0');
	if (n == -2147483648)
	{
		tab[0] = 8;
		i = 1;
		n = -214748364;
	}
	n *= sign_of(n);
	while (n > 0)
	{
		tab[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i > -1)
	{
		ft_putchar(tab[i] + 48);
		i--;
	}
}
