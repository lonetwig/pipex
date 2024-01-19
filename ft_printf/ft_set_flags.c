/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:48:01 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 15:10:07 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_vals(t_state *state, char c, char **str)
{
	if (c == '0' && !((*str)[1] >= '0' && (*str)[1] <= '9'))
		return ;
	if (c >= '0' && c <= '9')
	{
		state->val = ft_atoi_for_flags(str);
		(*str)--;
	}
	if (c == '.')
	{
		state->f_dot = 1;
		if ((*str)[1] >= '0' && (*str)[1] <= '9')
		{
			(*str)++;
			state->dot_val = ft_atoi_for_flags(str);
			(*str)--;
		}
		else
			state->dot_val = 0;
	}
}

void	set_flags(t_state *state, char c, char **str)
{
	if (c == '-')
	{
		state->f_zero = 0;
		state->f_minus = 1;
	}
	if (c == '0' && !state->f_minus)
		state->f_zero = 1;
	if (c == '#')
		state->f_diez = 1;
	if (c == ' ' && !state->f_plus)
		state->f_spc = 1;
	if (c == '+')
	{
		state->f_spc = 0;
		state->f_plus = 1;
	}
	get_vals(state, c, str);
}
