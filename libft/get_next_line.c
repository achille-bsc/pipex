/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosc <abosc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:16:08 by ameduboi          #+#    #+#             */
/*   Updated: 2025/01/21 20:17:19 by abosc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(char *rest, int fd)
{
	char	*buffer;
	int		i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr_gnl(rest, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(rest);
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		rest = ft_strjoin_gnl(rest, buffer);
	}
	free(buffer);
	return (rest);
}

static char	*update_rest(char *line, char *rest)
{
	char			*new_rest;
	unsigned int	len;

	len = ft_strlen_gnl(line);
	new_rest = ft_substr_gnl(rest, len, ft_strlen_gnl(rest) - len);
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = ft_read_line(rest, fd);
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	while (rest[i] && rest[i] != '\n')
		i++;
	line = ft_substr_gnl(rest, 0, i + 1);
	rest = update_rest(line, rest);
	return (line);
}
/*
int     main(void)
{
        char    *str;
        int fd = open("persona", O_RDONLY);
        
        if (fd < 1)
                return (0);
        str = get_next_line(fd);
        while (str != NULL)
        {
                if (str)
                {
                        printf("%s", str);
                        free(str);
                        str = get_next_line(fd);
                }
        }
        close(fd);
        return(0);
}
*/
