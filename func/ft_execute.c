/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:37:35 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/18 11:42:44 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	free_all_str(char **all_str)
{
	int	i;

	i = 0;
	while (all_str[i])
	{
		free(all_str[i]);
		i++;
	}
	if (all_str)
		free(all_str);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*result;		

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	result = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (result);
}

static char	*check_and_get_command(char *cmd_name, char **cmd_paths)
{
	char	*tmp_str;

	while (*cmd_paths)
	{
		tmp_str = ft_strjoin("/", cmd_name);
		tmp_str = ft_strjoin(*cmd_paths, tmp_str);
		if (!access(tmp_str, F_OK))
			return (tmp_str);
		else
			free(tmp_str);
		cmd_paths++;
	}
	return (NULL);
}

void	ft_execute(char **full_cmd, char **cmd_paths)
{
	char	*cmd_path;

	cmd_path = check_and_get_command(full_cmd[0], cmd_paths);
	if (!cmd_path)
		ft_perror(NULL, NULL, full_cmd[0]);
	else
	{
		if (execve(cmd_path, full_cmd, NULL) == -1)
			ft_perror(full_cmd[0], NULL, NULL);
	}
	if (full_cmd)
		free_all_str(full_cmd);
}
