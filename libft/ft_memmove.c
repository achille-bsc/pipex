/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:28:37 by abosc             #+#    #+#             */
/*   Updated: 2024/10/16 20:59:59 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int		i;
	const unsigned char	*modifiable_src;
	unsigned char		*modifiable_dest;

	modifiable_src = src;
	modifiable_dest = dest;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src && dest < src + n)
	{
		i = n;
		while (i-- > 0)
			modifiable_dest[i] = modifiable_src[i];
		return (dest);
	}
	else
	{
		i = 0;
		while (i < n)
		{
			modifiable_dest[i] = modifiable_src[i];
			i++;
		}
		return (dest);
	}
}
