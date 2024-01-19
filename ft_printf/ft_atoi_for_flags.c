/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_for_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:32:18 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 15:09:31 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == ' ')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static void	is_oper(char c, char **str, int *neg)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg = (*neg) * -1;
		(*str)++;
		return ;
	}
}

int	ft_atoi_for_flags(char **str)
{
	int		n;
	int		neg;
	int		new_n;

	n = 0;
	neg = 1;
	while (is_space(**str))
		str++;
	is_oper(**str, str, &neg);
	while (**str)
	{
		if (**str < '0' || **str > '9')
			return (n * neg);
		new_n = n * 10 + (**str) - '0';
		if (new_n < n || new_n == 214748647)
		{
			(*str)++;
			return (-1);
		}
		n = new_n;
		(*str)++;
	}
	return (n * neg);
}
