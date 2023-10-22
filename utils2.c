/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:41:25 by wfaouzi           #+#    #+#             */
/*   Updated: 2023/10/22 17:49:16 by wfaouzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

long long	ft_atol(const char *str)
{
	long long	res;
	int			n;

	res = 0;
	n = 1;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		res = res * 10 + (*str - '0');
		if (res * n < INT_MIN || res * n > INT_MAX)
			errorx();
		str++;
	}
	return (res * n);
}

void	create_stack(t_stacks *a, int size, int top)
{
	a->data = (int *)malloc(sizeof(int) * size);
	a->top = top;
}
int	pick_divider(int len, int len_a, int smaller)
{
	if (len > 250 && len_a > 250)
	{
		if (smaller == len_a / 6)
			return (1);
	}
	else if (len > 149 || len_a < 11)
	{
		if (smaller == len_a / 4)
			return (1);
	}
	else if (len < 150 && len_a > 10)
	{
		if (smaller == len_a / 2)
			return (1);
	}
	return (0);
}

char	*join_helper_get(char *ret, char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
		j++;
	}
	ret[j++] = ' ';
	i = 0;
	while (str2[i])
	{
		ret[j] = str2[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_strjoinx(char *str1, char *str2)
{
	int		str1_len;
	int		str2_len;
	char	*ret;

	str1_len = 0;
	str2_len = 0;
	ret = NULL;
	if (str1)
		str1_len = ft_strlen(str1);
	if (!str1)
	{
		str1 = "";
		str1_len = 0;
	}
	if (!str2)
		return (NULL);
	str2_len = ft_strlen(str2);
	ret = (char *)ft_calloc(sizeof(char), str1_len + str2_len + 2);
	if (!ret)
		return (NULL);
	ret = join_helper_get(ret, str1, str2);
	free((void *)str1);
	return (ret);
}
