/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 09:43:51 by ealislam          #+#    #+#             */
/*   Updated: 2024/01/18 11:23:13 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> 
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"
# define BUFFER_SIZE 50

typedef struct s_fds
{
	int	input;
	int	output;
}	t_fds;

typedef struct s_proc_data
{
	int	i;
	int	pipe_fd[2];
	int	parent_input_fd;
	int	pid;
}	t_proc_data;

typedef struct s_cmd_and_paths
{
	char	**all_cmds;
	char	**all_paths;
	int		cmd_count;
}	t_cmd_and_paths;

char	**ft_split(char const *s, char c);
int		ft_printf(const char *str, ...);
void	ft_perror(char *cmd, char *file, char *cmd_not_found);
int		ft_read(char **input_str, int fd);
void	itter_on_cmds(t_cmd_and_paths cmd_and_paths, t_fds fds);
void	ft_execute(char **full_cmd, char **cmd_paths);

#endif