/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
/*   Updated: 2025/02/26 04:56:20 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	child_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL || execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found\n", 2);
		temp = ft_strjoin("pipex | ", cmd_args[0]);
		ft_putstr_fd(temp, 2);
		free(temp);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
		free_tab(cmd_args);
		if (path)
			free(path);
		path = NULL;
		exit(127);
	}
	free(path);
	free_tab(cmd_args);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**path;
	char	*path_str;
	char	*temp;

	i = 0;
	path = NULL;
	path_str = NULL;
	if (access(cmd, F_OK) == 0)
		return (ft_strjoin("/bin/", cmd));
	path = truc(i, env, path);
	i = 0;
	while (path[i])
	{
		temp = gpath_end(path_str, path, cmd, i);
		if (temp)
			return (temp);
		i++;
	}
	if (path)
		free_tab(path);
	return (NULL);
}

void	parent_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL || execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found\n", 2);
		temp = ft_strjoin("pipex | ", cmd_args[0]);
		ft_putstr_fd(temp, 2);
		free(temp);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd("\n", 2);
		free_tab(cmd_args);
		if (path)
			free(path);
		path = NULL;
		exit(127);
	}
	free_tab(cmd_args);
	free(path);
}

void	child(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	if (fd[1] != -1)
		close(fd[1]);
	if (p_fd[0] != -1)
		close(p_fd[0]);
	closer(fd, p_fd);
	child_cmd_executer(cmds.value1, env);
}

void	parent(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	if (p_fd[1] != -1)
		close(p_fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	if (fd[1] != -1)
		close(fd[1]);
	if (p_fd[1] != -1)
		close(p_fd[1]);
	closer(fd, p_fd);
	parent_cmd_executer(cmds.value2, env);
}
