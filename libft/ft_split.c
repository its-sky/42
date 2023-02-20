/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:10:39 by mincshin          #+#    #+#             */
/*   Updated: 2022/07/07 11:24:16 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(char **p)
{
	int	i;

	i = 0;
	while (p[i] != 0)
	{
		free(p[i]);
		++i;
	}
}

static int	cnt_word(const char *s, char c)
{
	int			result;
	const char	*p;

	result = 0;
	p = NULL;
	while (*s)
	{
		if (*s != c && p == NULL)
			p = s;
		if (*s == c && p != NULL)
		{
			++result;
			p = NULL;
		}
		++s;
	}
	if (p != NULL)
		++result;
	return (result);
}

static char	*make_str(char *start, char *end)
{
	int		i;
	char	*p;

	p = (char *)malloc(((int)(end - start) + 2) * sizeof(char));
	if (p == NULL)
		return (0);
	i = 0;
	while (start <= end)
	{
		p[i++] = *start;
		++start;
	}
	p[i] = '\0';
	return (p);
}

static void	split_word(char **p, char *s, char c)
{
	char	*start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	start = NULL;
	while (*s)
	{
		if (*s != c && start == 0)
			start = s;
		if (*s == c && start != 0)
		{
			p[i++] = make_str(start, s - 1);
			if (p[i - 1] == 0)
			{
				free_list(p);
				return ;
			}
			start = 0;
		}
		++s;
	}
	if (start != 0)
		p[i++] = (char *)make_str(start, s - 1);
}

char	**ft_split(const char *s, char c)
{
	char	**p;
	int		size;

	if (!s)
		return (0);
	size = (int)cnt_word(s, c);
	p = (char **)malloc((size + 1) * sizeof(char *));
	if (p == 0)
		return (0);
	p[size] = 0;
	if (size == 0)
		return (p);
	split_word(p, (char *)s, c);
	if (p[0] == 0)
	{
		free(p);
		return (0);
	}
	return (p);
}
