/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:43:08 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/18 10:13:00 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	str_size(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	fill_string(const char *src, char *dst, char c)
{
	while (*src && *src != c)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}

static int	add_str_to_arr(char **arr, int *arr_i, char const *s, char c)
{
	int	i;

	i = 0;
	arr[*arr_i] = malloc(str_size(s, c) + 1);
	if (arr[*arr_i] == NULL)
	{
		while (i < *arr_i)
			free(arr[i++]);
		free(arr);
		return (0);
	}
	fill_string(s, arr[*arr_i], c);
	(*arr_i)++;
	return (1);
}

static int	fill_arr(char **arr, const char *s, char c)
{
	int	s_i;
	int	arr_i;

	s_i = 0;
	arr_i = 0;
	if (s[s_i] && s[s_i] != c)
	{
		if (!add_str_to_arr(arr, &arr_i, s, c))
			return (0);
	}
	s_i++;
	while (*s && s[s_i] && s[s_i - 1])
	{
		if (s[s_i] != c && s[s_i - 1] == c)
		{
			if (!add_str_to_arr(arr, &arr_i, s + s_i, c))
				return (0);
		}
		s_i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		count;
	int		i;

	if (s == NULL)
		return (NULL);
	count = 0;
	i = 0;
	if (s[i] && s[i] != c)
		count++;
	i++;
	while (*s && s[i] && s[i - 1])
	{
		if (s[i] != c && s [i - 1] == c)
			count++;
		i++;
	}
	arr = malloc((count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr[count] = NULL;
	if (!fill_arr(arr, s, c))
		return (NULL);
	return (arr);
}
