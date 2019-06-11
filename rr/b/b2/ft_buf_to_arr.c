/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:02:54 by drafe             #+#    #+#             */
/*   Updated: 2019/02/19 14:16:59 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

char		**ft_buf_to_arr(char *buf)
{
	char	**arr;
	int		len;
	int		n;
	int		j;
	int		i;

	i = 0;
	j = 0;
	n = -1;
	len = 0;
	if (!(arr = (char **)malloc(sizeof(arr)*2048)))
		write(2, "malloc error\n", 10);
	while (*buf == '\n')
	{
		buf++;
		n++;
	}
	write(1, buf, 512);
	if (buf[0] != n) 
	{
		write(2, "Nmap error\n", 11);
	}

	while (*buf != '\n')
	{
		buf++;
		len++;
	}

	while (i < n && buf != '\0')
	{
		while (j < len)
		{
			arr[i][j] = buf[j];
			j++;
		}
		i++;
	}
	return (arr);
}
