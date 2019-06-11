/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:43:23 by drafe             #+#    #+#             */
/*   Updated: 2019/05/28 19:33:12 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if ((!s) || (!(res = (char*)malloc(sizeof(char) * (len + 1)))))
		return (0);
	while (i <= start)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (s[start] == '\0')
			break ;
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}
