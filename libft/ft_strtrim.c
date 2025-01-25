/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:14:00 by abosc             #+#    #+#             */
/*   Updated: 2024/10/24 20:00:19 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *set)
{
	char	*str;
	size_t	trimmed_len;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trimmed_len = ft_strlen(s1);
	while (*s1 && ft_strchr(set, s1[trimmed_len - 1]))
		trimmed_len--;
	str = malloc(trimmed_len + 1);
	if (str)
		ft_strlcpy(str, s1, trimmed_len + 1);
	return (str);
}
