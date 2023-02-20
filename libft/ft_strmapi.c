/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:20:32 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/07 11:29:09 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	idx;
	char			*str;

	if (!s)
		return (0);
	idx = 0;
	len = (unsigned int)(ft_strlen(s));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (idx < len)
	{
		str[idx] = f(idx, s[idx]);
		++idx;
	}
	str[idx] = '\0';
	return (str);
}
