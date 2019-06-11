/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:04:59 by drafe             #+#    #+#             */
/*   Updated: 2019/02/19 14:27:08 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

void		ft_enter_map(char *str)
{
	char	*buf;
	int		fd;
	int		ret;
		
	fd = open(str, O_RDONLY);
	if (!(buf = (char *)malloc(sizeof(buf) * 512)))
		write(2,"malloc error\n", 10);
	if (fd == -1)
	{
		write(2, "open() fail\n", 12);
	}
	while ((ret = read (fd,  buf, sizeof(buf))) > 0)
		write(1, buf, ret);
	write (1,"kek",3);
	ft_buf_to_arr(buf);
	if (close(fd) == -1)
	{
		write(2, "close() fail\n", 12);
	}
}

int			main(int argc, char **argv)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * 512);
	while (argc == 1)
	{
		read(0, ptr, 512);	
		i++;
		ft_enter_map(ptr);
	}
	free(ptr);
	if (argc > 1)
		ft_enter_map(argv[1]);
	return (0);
}