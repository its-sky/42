/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:54:22 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/09 13:37:08 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)s;
	i = 0;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			return ((char *)(s + i));
		++i;
	}
	if (p[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (0);
}
