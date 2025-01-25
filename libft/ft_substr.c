/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:54 by abosc             #+#    #+#             */
/*   Updated: 2024/10/25 17:56:45 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			s_len;

	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	s_len -= start;
	if (s_len < len)
		len = s_len;
	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		ft_memcpy(str, s + start, len);
		str[len] = '\0';
	}
	return (str);
}
