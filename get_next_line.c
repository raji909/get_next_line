/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/26 11:34:03 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_return_null(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_preparation(ssize_t *byte, char **buffer, char **rest)
{
	char	*incorrect_line;

	*byte = 1;
	*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buffer)
		return (NULL);
	if (*rest)
	{
		incorrect_line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	else
		incorrect_line = ft_strdup("");
	if (!incorrect_line)
	{
		free(*buffer);
		return (NULL);
	}
	return (incorrect_line);
}

static char	*ft_incorrect_line(int fd, char **new_line, char **rest)
{
	ssize_t	byte;
	char	*tmps;
	char	*buffer;
	char	*incorrect_line;

	incorrect_line = ft_preparation(&byte, &buffer, rest);
	if (!incorrect_line)
		return (NULL);
	while (!*new_line && byte)
	{
		tmps = incorrect_line;
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (ft_return_null(incorrect_line, buffer));
		buffer[byte] = '\0';
		incorrect_line = ft_strjoin(tmps, buffer);
		if (!incorrect_line)
			return (ft_return_null(tmps, buffer));
		free(tmps);
		*new_line = ft_strchr(incorrect_line, '\n');
	}
	free(buffer);
	return (incorrect_line);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*new_line;
	char		*incorrect_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	incorrect_line = ft_incorrect_line(fd, &new_line, &rest);
	if (!incorrect_line || !*incorrect_line)
		return (ft_return_null(incorrect_line, NULL));
	if (!new_line)
	{
		if (rest)
			free(rest);
		return (incorrect_line);
	}
	rest = ft_strdup(&new_line[1]);
	new_line[1] = '\0';
	line = ft_strdup(incorrect_line);
	free(incorrect_line);
	return (line);
}
