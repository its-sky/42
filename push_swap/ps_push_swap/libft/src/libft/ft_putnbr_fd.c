/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:48:33 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr_fd_recursive(int n, int fd, int sign)
{
	char	ch;

	ch = '0' + n % 10 * sign;
	if (n / 10 == 0)
	{
		if (sign == -1)
			write(fd, "-", 1);
		write(fd, &ch, 1);
		return ;
	}
	ft_putnbr_fd_recursive(n / 10, fd, sign);
	write(fd, &ch, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_putnbr_fd_recursive(n, fd, sign);
}
