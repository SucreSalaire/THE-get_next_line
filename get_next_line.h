/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:40:07 by salmou            #+#    #+#             */
/*   Updated: 2024/12/05 16:14:26 by salmou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct t_state
{
	char	*buf;
	char	flag;
}	t_state;

char	*get_next_line(int fd);
size_t	get_endline(char *buf);
char	*ft_strjoin(char *dst, char *src);
size_t	ft_strlen(char const *s);
char	*ft_substr(char const *s, size_t start, size_t len);
char	get_nextstate(char c, char c_case);
char	*ft_free(char **buf, char **s_buf);
void	extract_line(char **buf, char **s_buf, ssize_t end);
ssize_t	read_buf(int fd, char **buf);
char	*manage_fd(int fd, t_state **s);
#endif
