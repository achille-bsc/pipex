/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:31:49 by ameduboi          #+#    #+#             */
/*   Updated: 2025/01/21 20:22:17 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *line)
{
	size_t	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[++i])
		result[i] = s1[i];
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	free(s1);
	return (result);
}

int	ft_strchr_gnl(char *s, int c)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = (char *)s;
	if (!s)
		return (0);
	while (s[i])
	{
		if (ptr[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	if (!s[0])
		return (NULL);
	if (start > ft_strlen_gnl(s) || len == 0)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
