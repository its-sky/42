/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:48:30 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/15 14:15:03 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*p;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	j = 0;
	p = (char *)malloc(len * sizeof(char));
	if (p == (void *)0)
		return (0);
	while (s1[j] != '\0')
		p[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[i] = '\0';
	return (p);
}

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		++cnt;
	return (cnt);
}
