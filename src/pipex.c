/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:10:10 by abosc             #+#    #+#             */
/*   Updated: 2025/01/25 04:16:42 by abosc            ###   ########.fr       */
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

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		execve(cmd2, (char *[]){cmd2, file2, NULL}, NULL);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execve(cmd1, (char *[]){cmd1, file1, NULL}, NULL);
	}
}
