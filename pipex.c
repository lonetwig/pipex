/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:32:38 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/18 11:42:00 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static int	find_path_index(char *str[])
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == 'P' && str[i][1] == 'A' &&
		str[i][2] == 'T' && str[i][3] == 'H')
			return (i);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_cmd_and_paths	cmd_and_paths;
	t_fds			fds;

	if (argc <= 4 || argc >= 6)
		exit(1);
	cmd_and_paths.all_paths = ft_split(envp[find_path_index(envp)] + 5, ':');
	fds.input = open(argv[1], O_RDONLY);
	fds.output = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	cmd_and_paths.all_cmds = argv + 1;
	cmd_and_paths.cmd_count = argc - 1;
	itter_on_cmds(cmd_and_paths, fds);
	free_all_str(cmd_and_paths.all_paths);
}
