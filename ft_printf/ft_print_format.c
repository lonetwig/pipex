/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:45:53 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 13:21:44 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_string(char *str, int *size, t_state *state)
{
	int	i;

	i = 0;
	while (str[i] && !state->f_dot)
	{
		if (!ft_putchar_and_incr(str + i, size, 1))
			return ;
		i++;
	}
	while (str[i] && state->f_dot && state->dot_val > i)
	{
		if (!ft_putchar_and_incr(str + i, size, 1))
			return ;
		i++;
	}
}

static void	print_char(char c, int *size)
{
	if (!ft_putchar_and_incr(&c, size, 1))
		return ;
}

static int	check_negation(char c, long long arg)
{
	if ((c == 'd' || c == 'i') && (int)arg < 0)
		return (1);
	return (0);
}

void	print_format(t_state *s, long long arg, char c, int *size)
{
	count_all_length(c, arg, s);
	ft_print_pre_flags(s, c, check_negation(c, arg), size);
	if (*size == -1)
		return ;
	if (c == 'c' || c == '%')
		print_char((char)arg, size);
	else if (c == 's')
		print_string((char *)arg, size, s);
	else if (c == 'x' && !(!arg && s->f_dot && !s->dot_val))
		ft_puthexa((unsigned int)arg, 0, size);
	else if (c == 'p' && !(!arg && s->f_dot && !s->dot_val))
		ft_puthexa((unsigned long long)arg, 0, size);
	else if (c == 'X' && !(!arg && s->f_dot && !s->dot_val))
		ft_puthexa((unsigned int)arg, 32, size);
	else if ((c == 'd' || c == 'i') && !(!arg && s->f_dot && !s->dot_val))
		ft_putnbr((int)arg, size);
	else if (c == 'u' && !(!arg && s->f_dot && !s->dot_val))
		ft_putunsigned((unsigned int)arg, size);
	else if (arg)
		print_char((char)arg, size);
	if (*size == -1)
		return ;
	ft_print_post_flags(s, c, size);
}
