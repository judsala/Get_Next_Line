/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdantas- <jdantas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:20:05 by jdantas-          #+#    #+#             */
/*   Updated: 2022/10/10 15:32:07 by jdantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *s)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		next[j++] = s[i++];
	next[j] = '\0';
	free(s);
	return (next);
}

char	*set_buffer(int fd, char *buffer)
{
	char	*reader;
	int		i;

	reader = malloc ((BUFFER_SIZE + 1) * sizeof(char));
	if (!reader)
		return (NULL);
	i = 1;
	while (!finder(buffer, '\n') && i != 0)
	{
		i = read(fd, reader, BUFFER_SIZE);
		if (i == -1)
		{
			free(reader);
			return (NULL);
		}
		reader[i] = '\0';
		buffer = ft_strjoin(buffer, reader);
	}
	free(reader);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf[fd] = set_buffer(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	else
	{
		line = get_line(buf[fd]);
		buf[fd] = next_line(buf[fd]);
	}
	return (line);
}
