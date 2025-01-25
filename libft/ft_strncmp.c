/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:58:25 by abosc             #+#    #+#             */
/*   Updated: 2024/10/23 17:39:06 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			break ;
		i++;
	}
	return (str1[i] - str2[i]);
}

// int main()
// {
// 	printf("%i\n", ft_strncmp("abcdefgh", "abcdwxyz", 4));
// 	printf("%i\n", strncmp("abcdefgh", "abcdwxyz", 4));
// 	return (0);
// }