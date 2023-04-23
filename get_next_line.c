/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: an-zue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 00:07:28 by an-zue            #+#    #+#             */
/*   Updated: 2020/10/20 18:10:36 by an-zue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}

static size_t	length_line(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

static int		get_file_line(int fd, char **container)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;
	int		value;

	value = 1;
	while (value && !ft_strchr(*container, '\n'))
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		if ((value = read(fd, buf, BUFFER_SIZE)) == ERROR)
			break ;
		tmp = (*container) ? ft_strjoin(*container, buf) : ft_strdup(buf);
		free(*container);
		*container = tmp;
	}
	return (value);
}

int				get_next_line(int fd, char **line)
{
	static char	*container[MAX_FD];
	char		*tmp;
	int			value;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
			(value = get_file_line(fd, &container[fd])) == ERROR)
		return (ERROR);
	*line = ft_substr(container[fd], 0, length_line(container[fd]));
	if ((tmp = ft_strchr(container[fd], '\n')))
		tmp = ft_strdup(tmp + 1);
	free(container[fd]);
	container[fd] = tmp;
	return ((value) ? LINE_READ : END_OF_FILE);
}
