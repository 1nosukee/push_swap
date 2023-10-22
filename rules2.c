/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:40:57 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 16:06:51 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stacks *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		i = a->top;
		temp = a->data[i];
		while (i > 0)
		{
			a->data[i] = a->data[i - 1];
			i--;
		}
		a->data[i] = temp;
		write(1, "ra\n", 4);
		return (1);
	}
	else
		return (0);
}
int	rb(t_stacks *b)
{
	int	i;
	int	temp;

	if (b->top > 0)
	{
		i = b->top;
		temp = b->data[i];
		while (i > 0)
		{
			b->data[i] = b->data[i - 1];
			i--;
		}
		b->data[i] = temp;
		ft_putstr_fd("rb\n", 1);
		return (1);
	}
	else
		return (0);
}

int	rra(t_stacks *a)
{
	int	i;
	int	temp;

	if (a->top > 0)
	{
		i = 0;
		temp = a->data[0];
		while (i < a->top)
		{
			a->data[i] = a->data[i + 1];
			i++;
		}
		a->data[i] = temp;
		ft_putstr_fd("rra\n", 1);
		return (1);
	}
	else
		return (0);
}
int	rrb(t_stacks *b)
{
	int	i;
	int	temp;

	if (b->top > 0)
	{
		i = 0;
		temp = b->data[0];
		while (i < b->top)
		{
			b->data[i] = b->data[i + 1];
			i++;
		}
		b->data[i] = temp;
		ft_putstr_fd("rrb\n", 1);
		return (1);
	}
	else
		return (0);
}
