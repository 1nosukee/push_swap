/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:23:29 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 17:07:28 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stacks *a, t_stacks *b)
{
	int	min_index;

	while (a->top > 2)
	{
		min_index = ft_minimum(a);
		if (min_index == a->top)
			pb(a, b);
		else if (min_index > a->top - min_index)
			ra(a);
		else if (min_index <= a->top - min_index)
			rra(a);
	}
	sort_3(a, b);
	while (b->top >= 0)
		pa(a, b);
}
void	sort_3(t_stacks *a, t_stacks *b)
{
	int	mini;

	mini = ft_minimum(a);
	if (if_sorted(a) == 1 && b->top == -1)
		exit(1);
	while (if_sorted(a) == 0 && a->top <= 2)
	{
		if (mini == a->top - 2 && a->data[a->top] > a->data[a->top - 1])
		{
			sa(a);
			rra(a);
		}
		else if (mini == a->top - 1 && a->data[a->top] > a->data[a->top - 2])
			ra(a);
		else if (mini == a->top - 1)
			sa(a);
		else if (a->top == mini && a->data[a->top - 1] > a->data[a->top - 2])
		{
			sa(a);
			ra(a);
		}
		else if (a->top - 2 == mini && a->data[a->top] < a->data[a->top - 1])
			rra(a);
	}
}
int	if_sorted(t_stacks *a)
{
	int	i;

	if (a->top <= 0)
		return (1);
	i = 0;
	while (i < a->top)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
int	ft_minimum(t_stacks *a)
{
	int	i;
	int	min;
	int	k;

	i = 0;
	k = 0;
	min = 2147483647;
	while (i <= a->top)
	{
		if (a->data[i] < min)
		{
			min = a->data[i];
			k = i;
		}
		i++;
	}
	return (k);
}
int	ft_maximum(t_stacks *b)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i <= b->top)
	{
		if (b->data[i] > b->data[max])
			max = i;
		i++;
	}
	return (max);
}
