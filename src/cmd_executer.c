/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:02:39 by abosc             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/24 00:16:08 by abosc            ###   ########.fr       */
=======
/*   Updated: 2025/02/19 03:12:47 by abosc            ###   ########.fr       */
>>>>>>> 690f52df945d8197a52f96c8574c6070d32bade9
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
		i++;
	}
	free(tab);
}

void	child_cmd_executer(char *cmd, char **env)
{
	char	**cmd_args;
	char	*path;
	int		i;

	write(1, "child_cmd_executer\n", 19);
	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		(free_tab(cmd_args), free(path), exit(127));
	}
	if (execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found: \n", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		(free_tab(cmd_args), free(path), exit(127));
	}
	free(path);
	free_tab(cmd_args);
}

static inline char *sida(char **path, char *cmd, char *path_str, char *temp, int i)
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
<<<<<<< HEAD
	write(1, "mebi\n", 5);
	if (access(cmd, F_OK) == 0)
		return (cmd);
	write(1, "ici\n", 4);
=======
	if (access(cmd, F_OK) == 0)
		return (cmd);
>>>>>>> 690f52df945d8197a52f96c8574c6070d32bade9
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
<<<<<<< HEAD
	write(1, "la\n", 3);
=======
>>>>>>> 690f52df945d8197a52f96c8574c6070d32bade9
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
	if (path == NULL)
	{
		ft_putstr_fd("pipex | command not found: ", 2);
		temp = ft_strjoin("pipex | ", cmd_args[0]);
		ft_putstr_fd(temp, 2);
		free(temp);
		ft_putstr_fd("\n", 2);
		free_tab(cmd_args);
		free(path);
		exit(127);
	}
	if (execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex | command not found: \n", 2);
		ft_putstr_fd(ft_strjoin("pipex | ", cmd_args[0]), 2);
		ft_putstr_fd("\n", 2);
		free_tab(cmd_args);
		free(path);
		exit(127);
	}
	free_tab(cmd_args);
	free(path);
}

void	child(int p_fd[2], int fd[2], t_values cmds, char **env)
{
	dup2(fd[0], 0);
	close(p_fd[0]);
	// write(1, "ici\n", 4);
	dup2(p_fd[1], 1);
	// write(1, "ici\n", 4);
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
