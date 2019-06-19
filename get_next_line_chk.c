/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_chk.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:56:54 by drafe             #+#    #+#             */
/*   Updated: 2019/06/10 18:36:52 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>
int				main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			fd2;
	int			i;
	int			out;

	fd2 = 0;
	out = 0;
	argc = argc + 1 - 1;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	ft_putstr("\n\nFD:");
	ft_putnbr(fd);
	ft_putstr("|__X___X___X_____START_TEST1_____X___X___X__|\n");
	while (i < 7)
	{
		out = get_next_line(fd, &line);
		printf("\n\n[ENTER_GNL=%d=END_GNL]\nline[%d]:|%s|:=|%p|", out, i, line, line);
		i++;
	}
	close (fd);
	/*i = 0;
	fd2 = open(g3.txt.mine, O_CREAT | O_RDWR | O_TRUNC, 0755);
	ft_putstr("\n\nFD_2:");
    ft_putnbr(fd2);
    ft_putstr("|_____________START_TEST2_____________|\n");
    while (i++ < 10)
    {
        ft_putstr("\n[ENTER_GNL\n");
        ft_putnbr(get_next_line(fd2, &line));
        ft_putstr("\nEND_GNL]\n\nLINE[");
        ft_putnbr(i);
        ft_putstr("]:|");
        ft_putstr(line);
        ft_putstr("|");
    }
	close (fd2);
	*/
//make re;gcc -Wall -Wextra -Werror get_next_line_chk.c get_next_line.a ./libft/libft.a 
//./a.out g3.txt > cat > newout
//static char *buf[10240] *s = ft_strjoin(s, tmp2) then tmp2 = ft_strjoin(tmp, tmp2) ;
//ulimit -a(show all) ulimit -n 10240(set n = 10240)ft_strjoin
//@k@s
/*{
		tmp[bytes] = '\0';
		printf("[s%zd=%s]\n", i, s);
		printf("[tmp%zd=%s]\n", i, tmp);
		s = ft_strjoin(s, tmp);
		printf("[s_2%zd=%s]\n", i, s);
		i++;
}*/
}
