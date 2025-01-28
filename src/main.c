/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42lehavre.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:00:16 by abosc             #+#    #+#             */
/*   Updated: 2025/01/28 00:39:18 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (!verify_args(argc, argv))
		return (1);
	pipex(argv, env);
	return (0);
}
