/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:10:10 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 01:48:49 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	pipex(char **argv, char **env)
{
	t_values	cmds;
	t_values	files;

	cmds.value1 = argv[2];
	cmds.value2 = argv[3];
	files.value1 = argv[1];
	files.value2 = argv[4];
	start_pipex(cmds, files, env);
}

void	start_pipex(t_values cmds, t_values files, char **env)
{
	int		fd[2];
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	fd[0] = open(files.value1, O_RDONLY);
	fd[1] = open(files.value2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[0] == -1 || fd[1] == -1 || pipe(p_fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		child(p_fd, fd, cmds, env);
	pid2 = fork();
	if (pid2 == -1)
		exit(1);
	if (pid2 == 0)
		parent(p_fd, fd, cmds, env);
	close(fd[0]);
	close(fd[1]);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
