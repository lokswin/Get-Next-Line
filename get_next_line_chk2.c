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
int				main()
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	printf("p[0]=%dp[1]=%d", p[0], p[0]);
	get_next_line(p[0], &line);
	len = 0;
	while (str[len] == line[len])
	{
		if (line[len] == '\0')
			break ;
		len++;
	}
	//len = ft_strcmp(line, str);
	printf("len=%d", len);
	//printf("%d=%dret{%d}==0\n\n%s\n\n%s", str[0], line[0],len, str, line);
	//make re;gcc -Wall -Wextra -Werror get_next_line_chk.c get_next_line.a ./libft/libft.a 
//./a.out g3.txt
}
