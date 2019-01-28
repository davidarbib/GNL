/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darbib <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:54:01 by darbib            #+#    #+#             */
/*   Updated: 2018/11/30 15:48:51 by darbib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_of(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	return (sign);
}

void		ft_putnbr_fd(int n, int fd)
{
	int		tab[11];
	int		i;

	i = 0;
	if (!n)
		ft_putchar_fd('0', fd);
	if (n == -2147483648)
	{
		tab[0] = 8;
		i = 1;
		n = -214748364;
	}
	n *= sign_of(n, fd);
	while (n > 0)
	{
		tab[i] = n % 10;
		n /= 10;
		i++;
	}
	i--;
	while (i > -1)
	{
		ft_putchar_fd(tab[i] + 48, fd);
		i--;
	}
}
