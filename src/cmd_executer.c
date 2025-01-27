/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 00:18:30 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void child_cmd_executer(char *cmd, int *fd, pid_t pid, char **env)
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0]);
	if (path == NULL)
	{
		ft_putstr_fd("pipex | command not found: ", 2);
		ft_putstr_fd(ft_strlcat("pipex | ", cmd_args[0], ft_strlen(cmd_args)), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve(path, cmd_args, NULL);
	return (path);
}

void parent_cmd_executer(char *cmd, int *fd, pid_t pid)
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0]);
	if (path == NULL)
	{
		ft_putstr_fd("pipex | command not found: ", 2);
		ft_putstr_fd(ft_strlcat("pipex | ", cmd_args[0], ft_strlen(cmd_args)), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	dup2(fd[1], 0);
	close(fd[0]);
	execve(path, cmd_args, NULL);
	return (path);
}
