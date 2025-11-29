/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/28 19:37:13 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return_null(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_preparation(char **buffer, ssize_t *byte)
{
	char	*line;

	*byte = 1;
	if (*buffer)
	{
		line = ft_strjoin("", *buffer);
		if (!line)
			return (NULL);
	}
	else
	{
		line = ft_strdup("");
		*buffer = malloc((size_t)(BUFFER_SIZE + 1) * sizeof(char));
		if (!*buffer)
			return (ft_return_null(line, NULL));
		(*buffer)[0] = '\0';
	}
	return (line);
}


char	*ft_line(int fd, char **new_line)
{
	char		*tmp;
	char		*line;
	static char	*buffer[1024];
	ssize_t		byte_read;

	line = ft_preparation(&buffer[fd], &byte_read);
	if (!line)
		return (NULL);
	while (!(*new_line = ft_strchr(buffer[fd], '\n')) && byte_read)
	{
		tmp = line;
		byte_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte_read < 0)
			return (ft_return_null(line, buffer[fd]));
		buffer[fd][byte_read] = '\0';
		line = ft_strjoin(tmp, buffer[fd]);
		if (!line)
			return (ft_return_null(tmp, buffer[fd]));
		free(tmp);
	}
	if (!*new_line)
		buffer[fd] = ft_return_null(buffer[fd], NULL);
	else
		ft_strcpy_rest(buffer[fd], &new_line[0][1]);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	new_line = NULL;
	line = ft_line(fd, &new_line);
	if (!line || !*line)
		return (ft_return_null(line, NULL));
	return (line);
}
