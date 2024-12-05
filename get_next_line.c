/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:44:23 by salmou            #+#    #+#             */
/*   Updated: 2024/12/05 03:09:22 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	get_nextstate(char c, char c_case)
{
	if (c_case == 0 && c == '\n')
		return (2);
	else if (c_case == 0)
		return (1);
	else if (c)
		return (4);
	return (0);
}

void	extract_line(char **buf, char **s_buf, ssize_t end)
{
	char	*ptr;

	if (s_buf && *s_buf)
	{
		free(*s_buf);
		*s_buf = NULL;
	}
	*s_buf = ft_substr(*buf, end + 1, ft_strlen(*buf) - end);
	ptr = ft_substr(*buf, 0, ft_strlen(*buf));
	free(*buf);
	*buf = ft_substr(ptr, 0, end + 1);
	free(ptr);
}

ssize_t	read_buf(int fd, char **buf)
{
	ssize_t	end;

	*buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	end = read(fd, *buf, BUFFER_SIZE);
	if (end > 0)
		(*buf)[end] = 0;
	return (end);
}

char	*get_next_line(int fd)
{
	static struct t_state	state;
	char					*buf;
	ssize_t					end;

	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE == 0)
	{
		state.flag = 0;
		return (ft_free((char **) NULL, &state.buf));
	}
	if (state.flag == 0 || state.flag == 1)
	{
		end = read_buf(fd, &buf);
		if (end <= 0)
			return (ft_free(&buf, &state.buf));
	}
	if (state.flag == 4)
		buf = ft_substr(state.buf, 0, ft_strlen(state.buf));
	end = get_endline(buf);
	state.flag = get_nextstate(buf[end], 0);
	if (state.flag == 1)
		return (ft_strjoin(buf, get_next_line(fd)));
	extract_line(&buf, &state.buf, end);
	state.flag = get_nextstate(state.buf[0], 1);
	return (buf);
}
/*
int	main(int ac, char **av)
{
	int		fd = open("file.txt", O_RDONLY);
	char	*ptr;
	int		i = 0;
	if (ac)
	{
		while (i++ < ft_atoi(av[1]))
		{
			ptr = get_next_line(fd);
			if (ptr)
			{
				printf("%s", ptr);
				free(ptr);
			}
		}
	}
	return (0);
}*/
