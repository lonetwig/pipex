/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:48:28 by ealislam          #+#    #+#             */
/*   Updated: 2023/11/16 15:09:54 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_type
{
	char	f_diez;
	char	f_minus;
	char	f_plus;
	char	f_spc;
	char	f_zero;
	char	f_dot;
	char	zero_x;
	int		val;
	int		dot_val;
	int		precision;
}	t_state;

typedef struct s_arg
{
	long long	arg;
	int			found;
}	t_arg;

void	ft_print_pre_flags(t_state *state, char c, int neg, int *size);
void	ft_print_post_flags(t_state *state, char c, int *size);
void	ft_string_filter(char **str, int *size, va_list args);
void	ft_puthexa(unsigned long long n, int upper, int *size);
void	set_flags(t_state *state, char c, char **str);
void	ft_putunsigned(unsigned int n, int *size);
void	ft_putnbr(int n, int *size);
int		ft_printf(const char *str, ...);
void	print_format(t_state *state, long long arg, char c, int *size);
int		ft_putchar_and_incr(char *c, int *size, unsigned int len);
void	count_all_length(char c, long long arg, t_state *s);
int		count_num_length(long long n);
int		count_hexa_length(unsigned long long n);
int		ft_strlen(char *s);
int		ft_atoi_for_flags(char **str);

#endif