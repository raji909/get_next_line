/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:25 by adraji            #+#    #+#             */
/*   Updated: 2025/11/28 19:33:59 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char    *s;

	if (!s1)
		return (NULL);
	s = malloc(ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char    *ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
void	ft_strcpy_rest(char *dest, char *src)
{
	size_t	i;

	if (!dest)
		return ;
	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len[2];
	size_t	i[2];
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	s = malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (!s)
		return (NULL);
	i[0] = 0;
	while (i[0] < len[0])
	{
		s[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (i[1] < len[1])
		s[i[0]++] = s2[i[1]++];
	s[i[0]] = '\0';
	return (s);
}
