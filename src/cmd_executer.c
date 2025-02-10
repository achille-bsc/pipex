/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
/*   Updated: 2025/02/10 18:21:04 by abosc            ###   ########.fr       */
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
	path = get_path(cmd_args[0], env);
	if (path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	if (execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found: \n", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
}

char *get_path(char *cmd, char **env)
{
	int     i;
	char    **path;
	char    *path_str;

	i = 0;
	path = NULL;
	
	if (access(cmd, F_OK) == 0)
		return cmd;

	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	i = 0;
	while (path[i])
	{
		path_str = ft_strjoin(path[i], "/");
		path_str = ft_strjoin(path_str, cmd);
		if (access(path_str, F_OK) == 0)
			return (path_str);
		i++;
	}
	return (NULL);
}

void	parent_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL)
	{
		ft_putstr_fd("pipex | command not found: ", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
	if (execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found: \n", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		exit(127);
	}
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
