/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:04:59 by drafe             #+#    #+#             */
/*   Updated: 2019/02/19 22:13:04 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

void		ft_enter_map(char *str)
{
	char	*buf;
	int		fd;
	int		bytes;
	int		i;

	i = 0;
	if (!(buf = (char *)malloc(sizeof(buf) * 512)))
	{		
		write(2, "malloc fail\n", 12);
		exit(1);
	}	
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		write(2, "open() fail\n", 12);
		exit(1);
	}	
	if ((bytes = read (fd,  buf, sizeof(buf) * 512)) == -1)
	{
		write(2, "read() fail\n", 12);
		exit(1);
	}
	buf[bytes + 1] = '\0';
	while(buf[i] != '\0')
	{
		ft_putchar(buf[i]);
		i++;
	}
	ft_buf_to_arr(buf);
	free(buf);
	if (close(fd))
	{
		write(2, "close() fail\n", 12);
		exit(1);
	}
}

int			main(int argc, char **argv)
{
	int bytes;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (argc == 1)	
	{
		if (argv[i][j] == '\n')
		{
			if ((bytes = read (0,  argv[i], sizeof(argv) * 512)) == -1)
			{
				write(2, "re0d() fail\n", 12);
				exit(1);
			}
			i++;
			j++;
			ft_putnbr(j);
		}
		else if (argv[i][j] == '\n')
		{
			j++;
			ft_putnbr(j);
		}
		argv[1][bytes + 1] = '\0';
		ft_enter_map(argv[1]);
	}
	i = 1;
	if (argc > i)
		ft_enter_map(argv[i]);
	return (0);
}
