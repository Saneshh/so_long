/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsolet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:44:42 by hsolet            #+#    #+#             */
/*   Updated: 2024/01/14 05:26:44 by hsolet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_buffer(char **str, ssize_t *read_size, int fd)
{
	char	*buffer;

	if (!ft_strchr(*str, '\n'))
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return ;
		*read_size = read(fd, buffer, BUFFER_SIZE);
		if (*read_size <= 0)
		{
			*read_size = 0;
			free(buffer);
			return ;
		}
		*str = ft_strjoin(*str, buffer);
		free(buffer);
	}
}

char	*the_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	line = ft_calloc((ft_strlen(str) + 1), sizeof(char));
	while (str[i] != '\n' && str[i])
		i++;
	line[i] = 0;
	while (i >= 0)
	{
		line[i] = str[i];
		i--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	ssize_t		read_size;
	char		*line;

	read_size = 1;
	while (!ft_strchr(str, '\n') && read_size > 0)
		read_buffer(&str, &read_size, fd);
	line = the_line(str);
	if (line && !*line)
	{
		free(line);
		free(str);
		str = NULL;
		return (NULL);
	}
	if ((read_size <= 0 || ft_strlen(line) == ft_strlen(str) + 1))
	{
		free(str);
		str = NULL;
		return (line);
	}
	str = ft_substr(str, ft_strlen(line), ft_strlen(str));
	return (line);
}
