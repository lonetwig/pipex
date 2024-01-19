/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:57:32 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/13 11:06:41 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putnbr(long long l_n, int *size)
{
	char	c;

	if (l_n < 10)
	{
		c = (l_n % 10) + '0';
		if (*size != -1 && !ft_putchar_and_incr(&c, size, 1))
			return ;
		return ;
	}
	putnbr(l_n / 10, size);
	c = (l_n % 10) + '0';
	if (*size != -1 && !ft_putchar_and_incr(&c, size, 1))
		return ;
}

void	ft_putnbr(int n, int *size)
{
	long long	l_n;

	l_n = n;
	if (n < 0)
		l_n = -l_n;
	putnbr(l_n, size);
}

void	ft_putunsigned(unsigned int n, int *size)
{
	long long	l_n;

	l_n = n;
	putnbr(l_n, size);
}
