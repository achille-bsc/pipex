/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:07:10 by abosc             #+#    #+#             */
/*   Updated: 2024/10/23 17:46:17 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*s_cpy;
	char	*s_dup;

	i = 0;
	s_len = ft_strlen(s);
	s_cpy = (char *)s;
	s_dup = ft_calloc(s_len + 1, sizeof(char));
	if (!s_dup)
		return (NULL);
	while (i < s_len)
	{
		s_dup[i] = s_cpy[i];
		i++;
	}
	return (s_dup);
}
