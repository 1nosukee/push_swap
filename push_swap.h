/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:40:26 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 18:06:24 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

typedef struct s_tools
{
	char	**g;
	int		i;
	int		j;
	int		z;
	int		*sort;
}			t_tools;

typedef struct push_stacks
{
	int		*data;
	int		top;
	int		start;
	int		end;
	int		range;
}			t_stacks;
 
int			sa(t_stacks *a);
int			sb(t_stacks *b);
int			pa(t_stacks *a, t_stacks *b);
int			pb(t_stacks *a, t_stacks *b);
int			ra(t_stacks *a);
int			rb(t_stacks *b);
int			rra(t_stacks *a);
int			rrb(t_stacks *b);
int			*bubble_sort(t_stacks *a);
int			ft_range(int a, int list[], int start, int end);
void		range_max(t_stacks *a, t_stacks *b, int list[]);
void		range_min(t_stacks *a, t_stacks *b, int list[]);
void		push_top(t_stacks *a, t_stacks *b);
int			if_sorted(t_stacks *a);
void		sort_3(t_stacks *a, t_stacks *b);
void		sort_4(t_stacks *a, t_stacks *b);
int			ft_maximum(t_stacks *b);
int			ft_minimum(t_stacks *a);
void		init_stack(t_stacks *a, t_stacks *b, int len);
void		to_stack(t_stacks *a, t_tools *s);
void		sort_stack(t_stacks *a, t_stacks *b, t_tools *s);
long long	ft_atol(const char *str);
char		*ft_strjoinx(char *str1, char *str2);
void		errorx(void);
int			ft_size(char **str);
void		ft_check(int a[], int b, int len); 
char		*split_argc_v(char *argv[], int argc);
int			check_input(char *str);
void		check_g(char **str);
void		check_helper(char *str, int i, int sign, int number);
void		create_stack(t_stacks *a, int size, int top);
int	find_middle(int *list, int len_a, int len);


#endif
