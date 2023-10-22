/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:41:11 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 16:43:59 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stacks *a, t_stacks *b, int len)

{
	a->data = (int *)malloc(sizeof(int) * len);
	a->top = len;
	b->data = (int *)malloc(sizeof(int) * len);
	b->top = -1;
}

void	to_stack(t_stacks *a, t_tools *s)
{
	int currentvalue;

	while (s->i >= 0 && s->j < ft_size(s->g))
	{
		currentvalue = ft_atol(s->g[s->j++]);
		if (currentvalue == 0 && s->z++ != 0)
		{
			write(2, "Error\n", 6);
			return ;
		}
		if (currentvalue != 0)
		{
			ft_check(a->data, currentvalue, ft_size(s->g));
		}
		a->data[s->i--] = currentvalue;
	}
}

void	sort_stack(t_stacks *a, t_stacks *b, t_tools *s)

{
	if (if_sorted(a) == 0)
	{
		if (a->top <= 2)
			sort_3(a, b);
		else if (a->top <= 4)
			sort_4(a, b);
		else if (a->top >= 4 && a->top <= 100)
			range_min(a, b, s->sort);
		else if (a->top > 100)
			range_max(a, b, s->sort);
	}
}