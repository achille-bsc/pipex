/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gpath_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:05:54 by abosc             #+#    #+#             */
/*   Updated: 2025/02/26 03:06:03 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*gpath_end(char *path_str, char **path, char *cmd, int i)
{
	char	*temp;

	temp = NULL;
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
	return (NULL);
}

char	**truc(int i, char **env, char **path)
{
	while (env[i++])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split(env[i] + 5, ':');
			break ;
		}
	}
	return (path);
}
