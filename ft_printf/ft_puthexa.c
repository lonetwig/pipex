/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:41:26 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/13 14:47:12 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned long long n, int upper, int *size)
{
	char	*str;
	char	c;

	str = "0123456789abcdef";
	if (n % 16 > 9)
		c = str[n % 16] - upper;
	else
		c = str[n % 16];
	if (n <= 15)
	{
		if (*size != -1 && !ft_putchar_and_incr(&c, size, 1))
			return ;
		return ;
	}
	ft_puthexa(n / 16, upper, size);
	if (*size != -1 && !ft_putchar_and_incr(&c, size, 1))
		return ;
}
