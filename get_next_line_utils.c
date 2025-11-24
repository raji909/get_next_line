/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:14:25 by adraji            #+#    #+#             */
/*   Updated: 2025/11/17 00:49:27 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    size_t  i = 0;
    size_t  j = 0;
    char    *s;

    s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!s)
        return (NULL);

    while (s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        s[i + j] = s2[j];
        j++;
    }
    s[i + j] = '\0';
    return (s);
}

char    *ft_strmove(char *dest, const char *src)
{
    size_t i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
