/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:03:07 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:49:01 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (ft_strlen(s) <= start)
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
