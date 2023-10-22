/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:37:27 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 01:39:06 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	ft_check(int a[], int b, int len)
{
	while (len > 0)
	{
		if (a[len] == b)
			errorx();
		len--;
	}
}

char	*split_argc_v(char *argv[], int argc)
{
	int		i;
	char	*res;

	if (!argv || argc < 2)
		return (NULL);
	i = 1;
	res = ft_strdup("");
	while (argv[i] && argc > 1)
	{
		res = ft_strjoinx(res, argv[i]);
		i++;
		argc--;
	}
	return (res);
}

int	ft_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}

void	errorx(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int	*bubble_sort(t_stacks *a)
{
	int	*res;
	int	i;
	int	j;

	res = (int *)malloc(sizeof(int) * (a->top + 1));
	i = 0;
	j = 0;
	while (i <= a->top)
	{
		res[i] = a->data[i];
		i++;
	}
	i = 0;
	while (i < a->top)
	{
		j = 0;
		while (j < a->top - i)
		{
			if (res[j] > res[j + 1])
				ft_swap(&res[j], &res[j + 1]);
			j++;
		}
		i++;
	}
	return (res);
}
