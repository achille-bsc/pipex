/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:03:14 by abosc             #+#    #+#             */
/*   Updated: 2025/01/25 04:15:34 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int verify_args(int argc, char **argv)
{
	if (argc != 5)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	if (access_file(argv[1]) == -1)
	{
		printf("Error: File %s does not exist\n", argv[1]);
		return (0);
	}
	if (access_file(argv[4]) == -1)
	{
		printf("Error: File %s does not exist\n", argv[4]);
		return (0);
	}
	return (1);
}

int access_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (1);
}
