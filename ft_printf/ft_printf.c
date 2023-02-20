/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:53:21 by mincshin          #+#    #+#             */
/*   Updated: 2022/11/09 20:47:36 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
	return (i);
}

int	printelse(char c)
{
	if (c == ' ')
		write(1, " ", 1);
	else if (c == '\n')
		write(1, "\n", 1);
	else if (c == '\t')
		write(1, "\t", 1);
	return (1);
}

int	printvar(char c, va_list *args)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(*args, int)));
	else if (c == 'p')
	{
		p = va_arg(*args, unsigned long long);
		if (p == 0)
			return (ft_putstr("0x0"));
		else
			return (ft_putstr("0x") + ft_putpointer(p));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		sum;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			if (!str[i])
				break ;
			sum += printvar(str[i], &args);
		}
		else
			sum += ft_putchar(str[i]);
		++i;
	}
	va_end(args);
	return (sum);
}
