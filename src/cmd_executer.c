/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/24 02:06:38 by abosc            ###   ########.fr       */
=======
/*   Updated: 2025/02/24 01:29:01 by abosc            ###   ########.fr       */
>>>>>>> 1995049b4245b07f9e523da85495188c5a04e73a
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

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

static inline char	*sida(char **path, char *cmd, char *path_str, char *temp,
		int i)
{
	while (path[i])
	{
		path_str = ft_strjoin(path[i], "/");
		if (!path_str)
			return (NULL);
		temp = ft_strjoin(path_str, cmd);
		if (!temp)
			return (NULL);
		free(path_str);
		if (access(temp, F_OK) == 0)
		{
			free_tab(path);
			return (temp);
		}
		free(temp);
		i++;
	}
	return (NULL);
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
	temp = NULL;
	if (access(cmd, F_OK) == 0)
<<<<<<< HEAD
		return (cmd);
=======
		return (ft_strjoin("/bin/", cmd));
>>>>>>> 1995049b4245b07f9e523da85495188c5a04e73a
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
	sida(path, cmd, path_str, temp, i);
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
	dup2(fd[0], 0);
	if (fd[1] != -1)
		close(fd[1]);
	// write(1, "ici\n", 4);
	dup2(p_fd[1], 1);
	// write(1, "ici\n", 4);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (p_fd[1] != -1)
		close(p_fd[1]);
	child_cmd_executer(cmds.value1, env);
}

void	parent(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	if (p_fd[1] != -1)
		close(p_fd[1]);
	dup2(p_fd[0], 0);
	dup2(fd[1], 1);
	if (fd[0] != -1)
		close(fd[0]);
	if (fd[1] != -1)
		close(fd[1]);
	if (p_fd[0] != -1)
		close(p_fd[0]);
	parent_cmd_executer(cmds.value2, env);
}
