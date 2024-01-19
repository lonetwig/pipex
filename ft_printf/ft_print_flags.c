/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:59 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 13:18:32 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	change_vals(t_state *state, char c, int neg)
{
	if (state->f_plus && (c == 'd' || c == 'i') && !neg)
	{
		state->val -= 1;
	}
	if (state->f_spc && (c == 'd' || c == 'i') && !neg)
	{
		state->val -= 1;
	}
}

void static	ft_print_pre_flags_p1(t_state *state, char c, int neg, int *size)
{
	if (!state->f_zero && !state->f_minus)
	{
		while (state->val > 0 && ft_putchar_and_incr(" ", size, 1))
			(state->val)--;
	}
	if (*size == -1)
		return ;
	if (neg && !ft_putchar_and_incr("-", size, 1))
		return ;
	if ((state->zero_x && c == 'x') || c == 'p')
		ft_putchar_and_incr("0x", size, 2);
	if (state->zero_x && c == 'X')
		ft_putchar_and_incr("0X", size, 2);
	if (state->f_plus && (c == 'd' || c == 'i') && !neg)
		ft_putchar_and_incr("+", size, 1);
}

void	ft_print_pre_flags(t_state *state, char c, int neg, int *size)
{
	change_vals(state, c, neg);
	ft_print_pre_flags_p1(state, c, neg, size);
	if (*size == -1)
		return ;
	if (state->f_spc && (c == 'd' || c == 'i') && !neg)
		ft_putchar_and_incr(" ", size, 1);
	if (*size == -1)
		return ;
	if (state->f_zero)
	{
		while (state->val > 0 && ft_putchar_and_incr("0", size, 1))
			state->val--;
	}
	if (*size == -1)
		return ;
	if (state->f_dot && (c != 's' && c != 'c'))
	{
		while (state->precision > 0 && ft_putchar_and_incr("0", size, 1))
			state->precision--;
	}
}

void	ft_print_post_flags(t_state *state, char c, int *size)
{
	int	i;

	i = 0;
	c = 1;
	if (state->f_minus)
	{
		while (state->val > 0 && ft_putchar_and_incr(" ", size, 1))
			state->val--;
	}
}
