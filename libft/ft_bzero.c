/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:26:21 by abosc             #+#    #+#             */
/*   Updated: 2024/10/22 23:24:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	unsigned char	*modifiable_s;

	modifiable_s = s;
	i = 0;
	while (i < n)
	{
		modifiable_s[i] = '\0';
		i++;
	}
}
