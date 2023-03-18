/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:59:00 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/18 11:04:58 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_sig(int sig)
{
	static char	temp;
	static int	bit;

	if (sig == SIGUSR1)
	{
		temp |= 0;
		if (bit < 7)
			temp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		temp |= 1;
		if (bit < 7)
			temp <<= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	if (signal(SIGUSR1, get_sig) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (signal(SIGUSR2, get_sig) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
