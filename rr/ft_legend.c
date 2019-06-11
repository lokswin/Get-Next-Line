/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 13:04:20 by drafe             #+#    #+#             */
/*   Updated: 2019/02/20 22:59:45 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_headers.h"

t_legend		ft_legend(char *buf)
{
	t_legend	tmp;
	char		*n_to_int;
	int			i;
	int			j;

	n_to_int = (char*)malloc(sizeof(char*) * 12);
	i = 0;
	j = 0;
	while (buf[i] != '\n')
		i++;
	while (j <= i - 3)
	{
		n_to_int[j] = buf[j];
		j++;
	}
	tmp.empty = buf[i - 3];
	tmp.obst = buf[i - 2];
	tmp.full = buf[i - 1];
	tmp.n = ft_atoi(n_to_int);
	tmp.map = ft_buf_to_arr(buf);
	free(n_to_int);
	return (tmp);
}
