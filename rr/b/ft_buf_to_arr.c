/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_to_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 22:02:54 by drafe             #+#    #+#             */
/*   Updated: 2019/02/19 21:13:08 by drafe            ###   ########.fr       */
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
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			n++;
			i++;
		}
		else if (buf[i] != '\n')
				i++;
	}
	while (buf[(i-2) - len] != '\n')
		len++;
//	ft_check_map(len, n);
	ft_putnbr(len);
	ft_putnbr(n);
	ft_putnbr(i);
	n = i - ((len * n) + n);
	i = 0;
	ft_putnbr(n);
	if (!(arr = (char**)malloc(sizeof(char*) * len)))
		write(2, "malloc error\n", 10);
	while (i < len ) 
	{
		arr[i] = (char*)malloc(len);
		i++;
	}
	i = 0;
	len = 0;
	while (buf[i + n] != '\0')
	{
		if (buf[i + n] == '\n')
		{
			i++;
			j++;
			len = 0;
		}
		else if(buf[i + n] != '\n')
		{
			arr[j][len] = buf[i + n];
			i++;
			len++;
		}
	}
	i = 0;
	ft_putchar(arr[10][0]);

	while (i < 12)
	{
		ft_putstr_fd(1, arr[i]);
		ft_putstr_fd(1, "=arr");
		ft_putnbr(i);
		
		i++;
	}
	return (arr);
}
