/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:45 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 15:02:23 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	check_format_specifier(char c, va_list args, int *found)
{
	if (c == 's' || c == 'p' || c == 'x' || c == 'X')
	{
		*found = 1;
		return ((long long)va_arg(args, long long));
	}
	else if (c == 'c' || c == 'd' || c == 'i' || c == 'u')
	{
		*found = 1;
		return ((long long)va_arg(args, int));
	}
	if (c == '%')
	{
		*found = 1;
		return ('%');
	}
	return (0);
}

static int	check_flags(char c)
{
	char	*str;

	str = "#-+0123456789 .";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static void	initialize_state(t_state *state)
{
	state->f_diez = 0;
	state->f_minus = 0;
	state->f_plus = 0;
	state->f_spc = 0;
	state->f_zero = 0;
	state->f_dot = 0;
	state->zero_x = 0;
	state->val = 0;
	state->dot_val = 0;
	state->precision = 0;
}

static int	ft_string_filter_p2(char **str, int *size, t_arg arg, t_state *s)
{
	if (check_flags(**str))
	{
		set_flags(s, **str, str);
	}
	else if (arg.found)
	{
		if (s->val == -1 || s->dot_val == -1)
		{
			*size = -1;
			return (1);
		}
		if ((void *)(arg.arg) == NULL && **str == 's')
			arg.arg = (long long)"(null)";
		print_format(s, arg.arg, **str, size);
		return (1);
	}
	else
	{
		s->val--;
		print_format(s, (long long)(**str), **str, size);
		return (1);
	}
	(*str)++;
	return (0);
}

void	ft_string_filter(char **str, int *size, va_list args)
{
	t_state		state;
	t_arg		arg;

	arg.found = 0;
	initialize_state(&state);
	while (**str)
	{
		arg.arg = check_format_specifier(**str, args, &(arg.found));
		if (ft_string_filter_p2(str, size, arg, &state))
			return ;
	}
}
