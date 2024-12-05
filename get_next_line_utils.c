/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:13:36 by salmou            #+#    #+#             */
/*   Updated: 2024/12/05 03:05:12 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_free(char **buf, char **s_buf)
{
	if (buf && *buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (s_buf && *s_buf)
	{
		free(*s_buf);
		*s_buf = NULL;
	}
	return (NULL);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	if ((ft_strlen(s) - start < len))
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = 0;
	if (len > 0)
		while (len--)
			ptr[len] = s[start + len];
	return (ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = ptr;
	if (!ptr)
		return (NULL);
	if (s1)
	{
		while (s1[i])
			*ret++ = s1[i++];
		free(s1);
	}
	if (s2)
	{
		while (s2[j])
			*ret++ = s2[j++];
		free(s2);
	}
	*ret = 0;
	return (ptr);
}

size_t	get_endline(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\n' && buf[i] && i < BUFFER_SIZE)
		i++;
	return (i);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
