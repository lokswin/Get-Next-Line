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

static char			*ft_gnl_write(const int fd, char *tmp, char *res)
{
	size_t			i;

	i = 0;
	while ((tmp[i] != '\n') && (tmp[i] != '\0'))
	{
		i++;
	}
	if (i == BUFF_SIZE)
	{
		free(res);
		res = NULL;
		ft_gnl_read(fd, res);
	}
	return (res);
}

static char		ft_gnl_read(const int fd, char *res)
{
	char			*tmp;
	size_t			len;
	size_t			bytes;
	size_t			empty;

	bytes = BUFF_SIZE;
	len = 0;
	empty = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	while ((bytes = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		res = ft_gnl_write(fd, tmp, res);
	}
	return (*res);
}

int					get_next_line(const int fd, char **line)
{
	char		*res;

	if (fd < 0)
		return (-1);
		if (!(res = (char *)malloc(sizeof(char) * 1)))
			return (0);
	else
		*line = ft_gnl_read(fd, res);
	if (*line[0] == 0)
		return (0);
	return (1);
}
