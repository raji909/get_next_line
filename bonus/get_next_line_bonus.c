/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/28 11:46:09 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_return_null(char *s1, char **s2)
{
	int	i;
	int	free_number;

	i = 0;
	free_number = 0;
	if (s1)
		free(s1);
	if (s2)
	{
		i = 0;
		while (i < 1024)
		{
			if (s2[i])
			{
				free(s2[i]);
				free_number++;
			}
		}
		if (!free_number)
			free(s2);
		i++;
	}
	return (NULL);
}

char	*ft_preparation(char ***buffer, int fd, ssize_t *byte)
{
	char	*tmp;
	char	*line;

	*byte = 1;
	tmp = ft_strdup("");
	line = NULL;
	if (*(buffer)[fd] && tmp)
	{
		line = ft_strjoin(tmp, *(buffer)[fd]);
		free(tmp);
		if (!line)
			return (NULL);
	}
	else if (tmp)
	{
		line = tmp;
		*(buffer) = malloc(1024 * sizeof(char *));
		if (!*(buffer))
			return (ft_return_null(line, *(buffer)));
		*(buffer)[fd] = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!*(buffer)[fd])
			return (ft_return_null(line, *(buffer)));
		*(buffer)[fd][0] = '\0';
	}
	return (line);
}


char	*ft_line(int fd, char **line, char **new_line)
{
	char		*tmp;
	static char	**buffer;
	ssize_t		byte_read;

	*line = ft_preparation(&buffer, fd, &byte_read);
	if (!*line)
		return (NULL);
	while (!(*new_*line = ft_strchr(buffer[fd], '\n')) && byte_read)
	{
		tmp = *line;
		byte_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte_read < 0)
			return (ft_return_null(*line, buffer));
		buffer[fd][byte_read] = '\0';
		*line = ft_strjoin(tmp, buffer[fd]);
		if (!*line)
			return (ft_return_null(tmp, buffer));
		free(tmp);
	}
	if (!*new_*line)
		buffer[fd] = ft_return_null(buffer[fd], NULL);
	else
		ft_strcpy_rest(buffer[fd], &new_*line[0][1]);
	return (*line);
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
