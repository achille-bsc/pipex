/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:02:02 by abosc             #+#    #+#             */
/*   Updated: 2025/02/23 23:40:11 by abosc            ###   ########.fr       */
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
	int		i;

	i = 0;
	cmd_args = ft_split(cmd, ' ');
	path = get_path(cmd_args[0], env);
	if (path == NULL || execve(path, cmd_args, env) == -1)
	{
		ft_putstr_fd("pipex: command child not found: ", 2);
		ft_putstr_fd(cmd_args[0], 2);
		ft_putstr_fd("\n", 2);
		(free_tab(cmd_args), free(path), path = NULL, exit(127));
	}
	free(path);
	path = NULL;
	free_tab(cmd_args);
}
