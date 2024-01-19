/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:19:18 by ealislam          #+#    #+#             */
/*   Updated: 2023/12/30 11:33:02 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	count_length(t_state *s, long long length)
{
	int	arg_len;
	int	j;

	arg_len = 0;
	j = 0;
	arg_len = length;
	if (arg_len > s->dot_val && s->f_dot)
		arg_len = s->dot_val;
	while (j + arg_len < s->val)
		j++;
	s->val = j;
}

static void	decimal_case(long long arg, t_state *s)
{
	int	place_taken;
	int	arg_length;

	place_taken = 0;
	arg_length = count_num_length((int)arg);
	count_length(s, arg_length);
	if (s->f_dot)
		s->f_zero = 0;
	if (((s->f_plus || s->f_spc) && s->val <= 1) || s->val < 1)
		place_taken = 1;
	if (!arg && s->f_dot && !s->dot_val && !place_taken)
		s->val++;
	if (s->f_dot && s->dot_val < arg_length)
		s->val -= arg_length - s->dot_val ;
	s->precision = s->dot_val - arg_length;
	if (arg < 0)
		s->precision++;
	if (s->precision > 0)
		s->val -= s->precision;
}

static void	unsigned_case(long long arg, t_state *s)
{
	int	arg_length;

	arg_length = count_num_length((unsigned int)arg);
	count_length(s, arg_length);
	if (s->f_dot)
		s->f_zero = 0;
	if (!arg && s->f_dot && !s->dot_val)
		s->val++;
	if (s->f_dot && s->dot_val < arg_length)
		s->val -= arg_length - s->dot_val ;
	s->precision = s->dot_val - arg_length;
	if (s->precision > 0)
		s->val -= s->precision;
}

static void	hexa_case(long long arg, t_state *s, char c)
{
	int	arg_length;

	if (c == 'p')
		arg_length = count_hexa_length((unsigned long long)arg);
	else
		arg_length = count_hexa_length((unsigned int)arg);
	count_length(s, arg_length);
	if (s->f_dot)
		s->f_zero = 0;
	if ((s->f_diez && arg) || c == 'p')
	{
		s->val -= 2;
		s->zero_x = 1;
	}
	if (!arg && s->f_dot && !s->dot_val)
		s->val++;
	if (s->f_dot && s->dot_val < arg_length)
		s->val -= arg_length - s->dot_val ;
	s->precision = s->dot_val - arg_length;
	if (s->precision > 0)
		s->val -= s->precision;
}

void	count_all_length(char c, long long arg, t_state *s)
{
	if (c == 'c' || c == '%')
		s->val--;
	if (c == 'd' || c == 'i')
		decimal_case(arg, s);
	if (c == 'u')
		unsigned_case((unsigned int)arg, s);
	if (c == 'x' || c == 'X')
		hexa_case((unsigned int)arg, s, c);
	if (c == 'p')
		hexa_case((unsigned long long)arg, s, c);
	if (c == 's')
		count_length(s, ft_strlen((char *)arg));
}
