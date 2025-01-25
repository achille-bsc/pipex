/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:28:20 by abosc             #+#    #+#             */
/*   Updated: 2024/10/24 21:00:41 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	const unsigned char	*modifiable_src;
	unsigned char		*modifiable_dest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	modifiable_src = src;
	modifiable_dest = dest;
	while (i < n)
	{
		modifiable_dest[i] = modifiable_src[i];
		i++;
	}
	return (dest);
}
