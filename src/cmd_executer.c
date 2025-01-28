/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 01:37:51 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", cmd_args[0]);
	if (path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	execve(path, cmd_args, env);
}

void	parent_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = ft_strjoin("/usr/bin/", cmd_args[0]);
	if (path == NULL)
	{
		ft_putstr_fd("pipex | command not found: ", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	execve(path, cmd_args, env);
}

void	child(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	close(p_fd[0]);
	dup2(fd[0], 0);
	dup2(p_fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(p_fd[1]);
	child_cmd_executer(cmds.value1, env);
}

void	parent(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	close(p_fd[1]);
	dup2(p_fd[0], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	close(p_fd[0]);
	parent_cmd_executer(cmds.value2, env);
}
