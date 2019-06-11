#include "ft_headers.h"

char		**ft_make_arr(char **arr, char *buf, int n)
{
	int		j;
	int		i;
	int		t;

	j = 0;
	i = 0;
	t = 0;
	while (buf[i + n] != '\0')
	{
		if (buf[i + n] == '\n')
		{
			i++;
			j++;
			t = 0;
		}
		else if (buf[i + n] != '\n')
		{
			arr[j][t] = buf[i + n];
			i++;
			t++;
		}
	}
	return (arr);
}

int			ft_buf_n(char *buf)
{
	int		i;
	int		n;

	i = 0;
	n = -1;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
		{
			n++;
			i++;
		}
		else if (buf[i] != '\n')
		{
			i++;
		}
	}
	return (n);
}

char		**ft_buf_to_arr(char *buf)
{
	char	**arr;
	int		len;
	int		n;
	int		i;
	int		max;

	i = 0;
	len = 0;
	n = ft_buf_n(buf);
	while (buf[i] != '\0')
		i++;
	while (buf[(i - 2) - len] != '\n')
		len++;
	max = i;
	i = 0;
	arr = (char**)malloc(sizeof(char*) * n);
	while (i < n)
	{
		arr[i] = (char*)malloc(len);
		i++;
	}
	n = max - ((len * n) + n);
	arr = ft_make_arr(arr, buf, n);
	return (arr);
}
