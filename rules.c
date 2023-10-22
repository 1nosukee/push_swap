/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:40:35 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 16:05:41 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stacks *a, t_stacks *b)
{
	if (b->top >= 0)
	{
		a->top++;
		a->data[a->top] = b->data[b->top];
		b->data[b->top] = 0;
		b->top--;
		ft_putstr_fd("pa\n", 1);
		return (1);
	}
	else
		return (0);
}
int	pb(t_stacks *a, t_stacks *b)
{
	if (a->top >= 0)
	{
		b->top++;
		b->data[b->top] = a->data[a->top];
		a->data[a->top] = 0;
		a->top--;
		ft_putstr_fd("pb\n", 1);
		return (1);
	}
	else
		return (0);
}

int	sa(t_stacks *a)
{
	int	temp;

	if (a->top >= 1)
	{
		temp = a->data[a->top];
		a->data[a->top] = a->data[a->top - 1];
		a->data[a->top - 1] = temp;
		ft_putstr_fd("sa\n", 1);
		return (1);
	}
	else
		return (0);
}

int	sb(t_stacks *b)
{
	int	temp;

	if (b->top >= 1)
	{
		temp = b->data[b->top];
		b->data[b->top] = b->data[b->top - 1];
		b->data[b->top - 1] = temp;
		ft_putstr_fd("sb\n", 1);
		return (1);
	}
	else
		return (0);
}
