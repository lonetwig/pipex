/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:14:19 by ealislam          #+#    #+#             */
/*   Updated: 2023/12/30 10:11:34 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		size;

	va_start(args, str);
	size = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			ft_string_filter((char **)&(str), &size, args);
		}
		else if (*str != '%')
			ft_putchar_and_incr((char *)str, &size, 1);
		if (size == -1)
		{
			va_end(args);
			return (-1);
		}
		str ++;
	}
	va_end(args);
	return (size);
}
