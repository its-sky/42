/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:59:02 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/08 10:46:58 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)(s + idx));
	}
	while (idx >= 0)
	{
		if (*(s + idx) == (char)c)
			return ((char *)(s + idx));
		idx--;
	}
	return (NULL);
}
