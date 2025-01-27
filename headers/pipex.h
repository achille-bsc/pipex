/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:05:46 by abosc             #+#    #+#             */
/*   Updated: 2025/01/27 23:42:47 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
// # include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

int		verify_args(int argc, char **argv);
int		access_file(char *file);
void	pipex(char **argv);
void	start_pipex(char *cmd1, char *cmd2, char *file1, char *file2);

#endif
