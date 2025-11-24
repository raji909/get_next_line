/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:48:07 by adraji            #+#    #+#             */
/*   Updated: 2025/11/17 00:48:41 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

boolean	ft_search(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*read_;
	static char	buffer[BUFFER_SIZE];
	boolean		lin_not_end;

	read_ = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!read_)
		return (NULL);
	read_[0] = '\0';
	lin_not_end = 1;
	while (lin_not_end)
	{
		tmp = read_;
		if (ft_search(buffer))
			lin_not_end = 0;
		read_ = ft_strjoin(tmp, buffer);
		free (tmp);
		if (!read_)
			return (NULL);
		size_t r = read(fd, buffer, BUFFER_SIZE - 1);
		if (r <= 0)
		{
		    buffer[0] = '\0';
		    return (read_);
		}
		buffer[r] = '\0';
		if (!buffer[0])
			return (NULL);
	}
	ft_strmove(buffer, &buffer[ft_strlen(buffer) + 1]);
	return (read_);
}
