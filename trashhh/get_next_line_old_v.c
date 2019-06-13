/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 20:26:45 by drafe             #+#    #+#             */
/*   Updated: 2019/06/06 18:14:00 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>

static char		*ft_gnl_write(char *ptr, char **line)
{
	static char	*s;
	int			i;
	int			n;

	i = 0;
	n = 0;
	ft_putstr("\ngnl_write_enter\n");
	while ((ptr[i] != '\n') && (ptr[i] != '\0'))
		i++;
	if (i < BUFF_SIZE)
		i++;
	s = ft_strjoin(s, ft_strsub(ptr, 0, i));
	while (i--)
	{
		s[n] = ptr[n];
		n++;
	}
	line = &s;
	ft_putstr("\ngnl_write_passed\n");
	ft_putstr(s);
	ft_putstr(":s");
	return (*line);
}

static int ft_gnl_read()
{

}

int				get_next_line(const int fd, char **line)
{
	char		*res;
	char		*tmp;
	int			bytes;

	bytes = BUFF_SIZE;
	if (!(res = (char *)malloc(sizeof(char) * 1)))
		return (0);
	while ((tmp = (char *)malloc(sizeof(char) * BUFF_SIZE)) && (bytes >= BUFF_SIZE))
	{
		bytes = read(fd, tmp, BUFF_SIZE);
		if (bytes == -1 || bytes == 0 )
		{
			ft_putstr_fd("\nread error\n", 2);
			return(-1);
		}
		ft_putstr("byte:");
		ft_putnbr(bytes);
		ft_gnl_write(tmp, line);
		ft_putnbr(0000);
	  /*ft_putstr("\ntmp:");
		ft_putstr(tmp);*/
		free(tmp);
		tmp = NULL;
	}
	return (1);
}
