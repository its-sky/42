/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:36:30 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:30 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_arr(int **arr, int **dup_ck, t_deque *a)
{
	t_node	*p;
	int		i;

	*arr = malloc(sizeof(int) * a->size);
	*dup_ck = malloc(sizeof(int) * a->size);
	if (arr == NULL || dup_ck == NULL)
		exit(1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		(*arr)[i] = p->data;
		(*dup_ck)[i] = 0;
		p = p->next;
		i++;
	}
}

void	init_deque(t_deque *a, t_deque *b)
{
	a->top = NULL;
	a->bot = NULL;
	b->top = NULL;
	b->bot = NULL;
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
}

int	check_sorted(t_deque *a, t_deque *b)
{
	int		i;
	t_node	*p;

	if (b->size)
		return (0);
	p = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (p->data > p->next->data)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
}

int	find_loc_a_null(t_deque *a, int find)
{
	t_node	*p;

	p = a->top;
	if (p->prev == NULL && a->bot->data > find && \
		p->data > find && a->bot->data > p->data)
		return (1);
	if (p->prev == NULL && a->bot->data < find && \
		p->data > find && a->bot->data < p->data)
		return (1);
	if (p->prev == NULL && a->bot->data < find && \
		p->data < find && a->bot->data > p->data)
		return (1);
	return (0);
}
