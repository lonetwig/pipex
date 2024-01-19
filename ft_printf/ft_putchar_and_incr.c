/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_and_incr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:04:24 by ealislam          #+#    #+#             */
/*   Updated: 2023/12/18 13:58:04 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_and_incr(char *c, int *size, unsigned int len)
{
	ssize_t	written_bin;

	written_bin = write (2, c, len);
	if (written_bin == (ssize_t)-1 || written_bin < (ssize_t)len)
	{
		*size = -1;
		return (0);
	}
	else
		(*size) += len;
	return (1);
}
