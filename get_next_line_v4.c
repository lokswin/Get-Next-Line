/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:26:45 by drafe             #+#    #+#             */
/*   Updated: 2019/06/08 16:35:00 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

static char		*ft_gnl_read(const int fd, char *res)
{
	char		*tmp;
	size_t		i;
	size_t		start;
	int			bytes;
	
	bytes = BUFF_SIZE;
	while ((tmp = (char *)malloc(sizeof(char) * BUFF_SIZE)) && (bytes >= BUFF_SIZE))
	{
		bytes = read(fd, tmp, BUFF_SIZE);
		i = 0;
		start = 0;
		while ((tmp[i] != '\n') && (i <= BUFF_SIZE))
			i++;
		if (i == 0)
		{
			free(tmp);
			tmp = NULL;
			break ;
		}
		if (i != BUFF_SIZE)
			res = ft_strjoin(res, ft_strsub(tmp, start, i));
		free(tmp);
		tmp = NULL;
	}
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	char		*res;

	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (0);
	res[0] = '\0';
	*line = ft_gnl_read(fd, res);
	if (*line[0] == 0)
		return (0);
	return (1);
}