/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_second_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:31:35 by mincshin          #+#    #+#             */
/*   Updated: 2022/09/06 15:42:06 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	charcount(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	putnbr_base(unsigned long long nb, char *base)
{
	if (nb >= 16)
		putnbr_base((nb / 16), base);
	ft_putchar(base[nb % 16]);
}

int	ft_puthex(int i, char x)
{
	char			*base;
	int				sum;
	unsigned int	c;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	sum = 0;
	c = (unsigned int)i;
	putnbr_base(c, base);
	sum += charcount(c);
	return (sum);
}

int	ft_putpointer(unsigned long long l)
{
	char	*base;
	int		sum;

	base = "0123456789abcdef";
	sum = 0;
	putnbr_base(l, base);
	sum += charcount(l);
	return (sum);
}
