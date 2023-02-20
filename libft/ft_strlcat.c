/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:36:46 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/06 15:01:59 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	tmp_i;

	i = 0;
	tmp_i = 0;
	while (dst[i] && i < dstsize)
		++i;
	while (src[tmp_i] && (i + tmp_i + 1) < dstsize)
	{
		dst[i + tmp_i] = src[tmp_i];
		++tmp_i;
	}
	if (i < dstsize)
		dst[i + tmp_i] = '\0';
	return (i + (size_t)ft_strlen(src));
}
