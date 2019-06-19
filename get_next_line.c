/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:26:45 by drafe             #+#    #+#             */
/*   Updated: 2019/06/10 18:11:57 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static char			*ft_gnl_write(char **s)
{
	size_t			line_len;
	size_t			s_len;
	char			*tmp_w;

	line_len = 0;
	tmp_w = NULL;
	s_len = ft_strlen(*s);
	while ((s[0][line_len] != '\n') && (s[0][line_len] != '\0'))
		line_len++;
	if (!(tmp_w = (char *)malloc(sizeof(char) * (line_len + 1))))
		return (NULL);
	tmp_w = ft_strsub(*s, 0, line_len);
	
	*s = ft_strsub(*s, line_len + 1, (s_len - line_len));
	return (tmp_w);
}

static int			ft_gnl_read(const int fd, char **s)
{
	char			*tmp;
	int				bytes;

	tmp = NULL;
	if (!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	ft_bzero(tmp, '\0');
	while ((bytes = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[bytes] = '\0';
		*s = ft_strjoin(*s, tmp);
	}
	free(tmp);
	tmp = NULL;
	if (bytes == -1)
		return (-1);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*out[10240];
	size_t			i;

	i = 0;
	if ((fd < 0) || (!line))
		return (-1);
	if (out[fd] == NULL)
	{
		if (!(out[fd] = (char *)malloc(sizeof(char) * 1)))
			return (0);
		out[fd][0] = '\0';
	}	
	if ((ft_gnl_read(fd, &out[fd])) == -1)
		return (-1);
	*line = ft_gnl_write(&out[fd]);
	if (*line == NULL)
		return (0);
	return (1);
}
