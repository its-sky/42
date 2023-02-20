/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:36:44 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:44 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	add_top(x, p);
	add_top(x, q);
	ft_printf("s%c\n", x->name);
}

void	swap_both(t_deque *x, t_deque *y)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	add_top(x, p);
	add_top(x, q);
	p = pop_top(y);
	q = pop_top(y);
	add_top(y, p);
	add_top(y, q);
	ft_printf("ss\n");
}

void	push(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(y);
	if (p == NULL)
		return ;
	add_top(x, p);
	ft_printf("p%c\n", x->name);
}
