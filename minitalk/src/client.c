/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 17:49:54 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/18 11:10:47 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int pid, char *str, int length)
{
	int	byte_index;
	int	bit_index;
	int	bit_temp;

	byte_index = 0;
	while (byte_index < length)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			bit_temp = str[byte_index] >> (7 - bit_index) & 1;
			if (bit_temp == 0)
				kill(pid, SIGUSR1);
			else if (bit_temp == 1)
				kill(pid, SIGUSR2);
			usleep(30);
			bit_index++;
		}
		byte_index++;
	}
}

void	get_str(int pid, char *str)
{
	int		length;
	char	*send;

	send = ft_strjoin(str, "\n");
	if (send == NULL)
		exit(1);
	length = ft_strlen(send);
	send_sig(pid, send, length);
	free(send);
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Argument is Wrong!!\n", 1);
		exit(1);
	}
	ft_atoi(av[1], &pid);
	if (pid < 100 || pid > 99998)
	{
		ft_putstr_fd("Invalid PID!!\n", 1);
		exit(1);
	}
	get_str(pid, av[2]);
	return (0);
}
