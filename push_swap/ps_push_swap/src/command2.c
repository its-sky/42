/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:36:36 by mincshin          #+#    #+#             */
/*   Updated: 2023/02/20 16:36:36 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate(t_deque *x)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(x, p);
	ft_printf("r%c\n", x->name);
}

void	rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(x, p);
	p = pop_top(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(y, p);
	ft_printf("rr\n");
}

void	reverse_rotate(t_deque *x)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(x, p);
	ft_printf("rr%c\n", x->name);
}

void	reverse_rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(x, p);
	p = pop_bot(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(y, p);
	ft_printf("rrr\n");
}
