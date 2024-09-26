/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybeltran <ybeltran@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:50:13 by ybeltran          #+#    #+#             */
/*   Updated: 2024/09/24 18:49:07 by ybeltran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_update_remainder(char *remainder, char *buffer)
{
	char	*temp;

	if (!remainder)
		remainder = ft_strdup(buffer);
	else
	{
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
	}
	return (remainder);
}

static char	*ft_extract_line(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		*newline_pos = '\0';
		line = ft_strdup(*remainder);
		temp = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = ft_update_remainder(remainder, buffer);
		if (ft_strchr(remainder, '\n'))
			return (ft_extract_line(&remainder));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (remainder && *remainder)
		return (ft_extract_line(&remainder));
	return (NULL);
}
