/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:50:22 by mincshin          #+#    #+#             */
/*   Updated: 2022/09/06 16:45:26 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static long	ft_count(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	putnbr(long n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	ft_itoa(int n)
{
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		l *= -1;
		size += 1;
	}
	size += ft_count(l);
	putnbr(l);
	return (size);
}

int	ft_uitoa(int n)
{
	unsigned int	u;
	int				size;

	size = 0;
	u = (unsigned int)n;
	size += ft_count(u);
	putnbr(u);
	return (size);
}
