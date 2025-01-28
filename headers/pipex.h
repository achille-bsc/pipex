/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:05:46 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 01:38:07 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "structures.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

int		verify_args(int argc, char **argv);
int		access_file(char *file);
void	pipex(char **argv, char **env);
void	start_pipex(t_values cmds, t_values files, char **env);
void	child_cmd_executer(char *cmd, char **env);
void	parent_cmd_executer(char *cmd, char **env);
void	child(int p_fd[2], int fd[2], t_values cmds, char **env);
void	parent(int p_fd[2], int fd[2], t_values cmds, char **env);
#endif
