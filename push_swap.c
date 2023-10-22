/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 03:28:24 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 16:10:46 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char		*res;
	t_tools		s;
	t_stacks	a;
	t_stacks	b;

	res = NULL;
	s.z = 0;
	if (argc >= 2)
	{
		if (argc == 2 && check_input(argv[1]) == 0)
			errorx();
		res = split_argc_v(argv, argc);
		s.g = ft_split(res, ' ');
		s.i = ft_size(s.g);
		init_stack(&a, &b, s.i);
		check_g(s.g);
		to_stack(&a, &s);
		s.sort = bubble_sort(&a);
		sort_stack(&a, &b, &s);
	}
	else
		exit(0);
}
