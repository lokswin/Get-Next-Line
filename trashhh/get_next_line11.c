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

static char			*ft_gnl_write(const int fd, char **s)
{
	size_t			len;
	char			*tmp_w;

	len = fd;
	len = 0;
	while ((s[0][len] != '\n') && (s[0][len] != '\0'))
		len++;
	if (!(tmp_w = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	tmp_w = ft_strsub(*s, 0, len);
	*s = ft_strsub(*s, len + 1, (ft_strlen(*s) - len));
	len = 0;
	return (tmp_w);
}

static int			ft_gnl_read(const int fd, char **s)
{
	char			*tmp;
	int				bytes;
	size_t			i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	ft_bzero(tmp, '\0');
	while ((bytes = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[bytes] = '\0';
		*s = ft_strjoin(*s, tmp);
	}
	printf("tmp=%s", tmp);
	free(tmp);
	tmp = NULL;
	if (bytes == -1)
		return (-1);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*out = NULL;
	int				read_res;

	if (fd < 0)
		return (-1);
	if (out == NULL)
	{
		if (!(out = (char *)malloc(sizeof(char) * 1)))
			return (0);
		out[0] = '\0';
	}
	read_res = ft_gnl_read(fd, &out);
	if ((read_res == -1) || (read_res == 0))
	{
		free(out);
		out = NULL;
	}
	printf("out1=%s", out);	
	*line = ft_gnl_write(fd, &out);
	printf("out1=%s", out);	
	if (*line[0] == 0)
		return (0);
	return (read_res);
}
