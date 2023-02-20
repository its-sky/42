/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:59:38 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/09 13:36:40 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntilen(int n)
{
	int		result;

	result = 0;
	if (n == -2147483648)
	{
		n /= 10;
		result += 1;
	}
	if (n < 0)
	{
		n *= -1;
		result += 1;
	}
	while (n > 0)
	{
		n /= 10;
		++result;
	}
	return (result);
}

static char	*recurr_makestr(char *p, int n, int idx)
{
	if (n == -2147483648)
	{
		p[ft_cntilen(n) - 1] = '8';
		n /= 10;
		--idx;
	}
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	if (n > 9)
		p = recurr_makestr(p, n / 10, idx - 1);
	p[idx] = '0' + (n % 10);
	return (p);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;

	if (n == 0)
	{
		p = (char *)malloc(2 * sizeof(char));
		p[0] = '0';
		p[1] = '\0';
		return (p);
	}
	len = ft_cntilen(n);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (p == NULL)
		return (0);
	p[len] = '\0';
	p = recurr_makestr(p, n, len - 1);
	return (p);
}
