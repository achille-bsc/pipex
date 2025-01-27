/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:10:10 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 00:21:13 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	pipex(char **argv)
{
	char	*cmd1;
	char	*cmd2;
	char	*file1;
	char	*file2;

	cmd1 = argv[2];
	cmd2 = argv[3];
	file1 = argv[1];
	file2 = argv[4];
	start_pipex(cmd1, cmd2, file1, file2);
}

void	start_pipex(char *cmd1, char *cmd2, char *file1, char *file2)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	fd[0] = open(file1, O_RDONLY);
	if (fd[0] == -1)
		exit(1);
	fd[1] = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		exit(1);
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child_cmd_executer(cmd1, fd, pid);
	pid2 = fork();
	if (pid2 == -1)
		exit(1);
	if (pid2 == 0)
		parent_cmd_executer(cmd2, fd, pid);
	waitpid(pid, NULL, 0);
	waitpid(pid, NULL, 0);
}
