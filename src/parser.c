/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:03:14 by abosc             #+#    #+#             */
/*   Updated: 2025/03/05 01:35:05 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	verify_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	if (access_file(argv[1]) == -1)
		ft_printf("Error: File %s does not exist\n", argv[1]);
	return (1);
}

int	access_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (1);
}
