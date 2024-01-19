/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:49:37 by ealislam          #+#    #+#             */
/*   Updated: 2023/12/30 14:09:45 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_perror(char *cmd, char *file, char *cmd_not_found)
{
	if (file && cmd)
		ft_printf("%s: %s: %s", cmd, file, strerror(errno));
	else if (file && !cmd)
		ft_printf("%s: %s", strerror(errno), file);
	else if (!file && cmd)
		ft_printf("%s: %s", strerror(errno), cmd);
	else if (cmd_not_found)
		ft_printf("%s: %s", "command not found", cmd_not_found);
	else
		ft_printf("%s", strerror(errno));
}
