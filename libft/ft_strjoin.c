/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:07:29 by abosc             #+#    #+#             */
/*   Updated: 2025/01/09 18:06:15 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	char	*s3;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	s3 = ft_calloc(total_len + 1, sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcat(s3, s1, ft_strlen(s1) + 1);
	ft_strlcat(s3, s2, total_len + 1);
	s3[total_len] = '\0';
	return (s3);
}
