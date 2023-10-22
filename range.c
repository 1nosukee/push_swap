/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:37:44 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 18:28:34 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_range(int a, int list[], int start, int end)
{
	int	k;

	k = start;
	while (k <= end)
	{
		if (a < list[start])
			return (2);
		if (a == list[k])
			return (1);
		k++;
	}
	return (0);
}

void	range_max(t_stacks *a, t_stacks *b, int list[])
{
	t_stacks	max;
	int middle;
	max.start = 0;
	max.end = 35;
	while (a->top != -1)
	{	
		middle = find_middle(list, max.start, max.end);
		max.range = ft_range(a->data[a->top], list, max.start, max.end);
		if (max.range == 1)
		{
			pb(a, b);
			max.start++;
			max.end++;
		}
		else if (max.range == 0)
			ra(a);
		else if (max.range == 2)
		{
			pb(a, b);
			rb(b);
			max.start++;
			max.end++;
		}
	}
	push_top(a, b);
}
void	range_min(t_stacks *a, t_stacks *b, int list[])
{
	t_stacks	min;
	int 		middle;
	min.start = 0;
	min.end = 15;
	while (a->top != -1)
	{	
		middle = find_middle(list, min.start, min.end);
		min.range = ft_range(a->data[a->top], list, min.start, min.end);
		if (min.range == 1)
		{
			pb(a, b);
			min.start++;
			min.end++;
		}
		else if (min.range == 0)
			ra(a);
		else if (min.range == 2)
		{
			pb(a, b);
			rb(b);
			min.start++;
			min.end++;
		}
	}
	push_top(a, b);
}
void	push_top(t_stacks *a, t_stacks *b)
{
	int	max;

	while (b->top != -1)
	{
		max = ft_maximum(b);
		while (max != b->top)
		{
			if (max > b->top / 2)
				rb(b);
			if (max <= b->top / 2)
				rrb(b);
			max = ft_maximum(b);
		}
		if (max == b->top)
			pa(a, b);
	}
}
int	find_middle(int *list, int len_a, int len)
{
	int	i;

	i = 0;
	while (i < len_a)
	{
		if (ft_range(list[len_a], list, len_a, len))
			return (list[len_a]);
		len_a++;
	}
	return (0);
}

