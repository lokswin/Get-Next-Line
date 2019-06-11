/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:26:45 by drafe             #+#    #+#             */
/*   Updated: 2019/06/10 17:24:19 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

static char			*ft_gnl_read(const int fd, char *res)
{
	char			*tmp;
	static	size_t			i = 0;
	size_t			len;
	size_t			bytes;
	size_t			empty;

	bytes = BUFF_SIZE;
	len = 0;
	empty = 0;
	if (!(tmp = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	bytes = read(fd, tmp, BUFF_SIZE);
	if (bytes <= 0)
		return(res);
	if (i < ft_strlen(tmp))
		tmp = ft_strsub(tmp, i, ft_strlen(tmp));
	i = 0;
	while ((tmp[len] != '\n') && (tmp[len] != '\0'))
	{
		len++;
		i++;
	}
	ft_putnbr(len);
    ft_putstr("=");
    ft_putnbr(i);
    ft_putstr(" ");
	if ((len == 0) || (len == BUFF_SIZE))
	{
		res = tmp;
		free(tmp);
		tmp = NULL;
		ft_gnl_read(fd, res);
	}
	if (i != BUFF_SIZE)
	{
													
	}
	i++;
	free(tmp);
	tmp = NULL;
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	char		*res;

	if (fd < 0)
		return (-1);
	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (0);
	res[0] = '\0';
	*line = ft_gnl_read(fd, res);
	if (*line[0] == 0)
		return (0);
	return (1);
}
