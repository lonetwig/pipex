/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:52:58 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/18 11:36:44 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	check_file(char *file_name, int input_fd)
{
	int	null_fd;

	null_fd = -1;
	if (!access(file_name, F_OK))
		return (input_fd);
	ft_perror(NULL, file_name, NULL);
	while (null_fd < 0)
		null_fd = open("/dev/null", O_RDONLY);
	return (null_fd);
}

void	child_process(t_proc_data *proc_data, t_cmd_and_paths *c_p, t_fds *fds)
{
	close(proc_data->pipe_fd[0]);
	dup2(proc_data->parent_input_fd, 0);
	if (proc_data->i < c_p->cmd_count - 2)
		dup2(proc_data->pipe_fd[1], 1);
	else
		dup2(fds->output, 1);
	ft_execute(ft_split(c_p->all_cmds[proc_data->i], ' '), c_p->all_paths);
	exit(0);
}

void	parent_process(t_proc_data *proc_data)
{
	close(proc_data->pipe_fd[1]);
	close(proc_data->parent_input_fd);
	proc_data->parent_input_fd = proc_data->pipe_fd[0];
	waitpid(proc_data->pid, NULL, 0);
	(proc_data->i)++;
}

void	itter_on_cmds(t_cmd_and_paths cmd_and_paths, t_fds fds)
{
	t_proc_data	proc_data;

	fds.input = check_file(cmd_and_paths.all_cmds[0], fds.input);
	proc_data.parent_input_fd = fds.input;
	proc_data.i = 1;
	while (proc_data.i < cmd_and_paths.cmd_count - 1)
	{
		if (pipe(proc_data.pipe_fd) == -1)
		{
			perror("pipe");
			exit(1);
		}
		proc_data.pid = fork();
		if (proc_data.pid == -1)
		{
			perror("fork");
			exit(1);
		}
		if (proc_data.pid == 0)
			child_process(&proc_data, &cmd_and_paths, &fds);
		else
			parent_process(&proc_data);
	}
}
