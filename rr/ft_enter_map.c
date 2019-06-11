#include "ft_headers.h"

void		ft_enter_map(char *str)
{
	char	*buf;
	int		fd;
	int		bytes;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(buf) * 512);
	if ((fd = open(str, O_RDONLY)) == -1)
		exit(1);
	if ((bytes = read(fd, buf, sizeof(buf) * 512)) == -1)
		exit(1);
	buf[bytes + 1] = '\0';
	while (buf[i] != '\0')
	{
		ft_putchar(buf[i]);
		i++;
	}
	ft_legend(buf);
	free(buf);
	if (close(fd))
		exit(1);
}

char		*ft_get_input()
{
	char *ptr;
	char *ptr2;
	int j;
	int i;
	int bytes;

	bytes = 1;
	i = 0;
	ptr = (char *)malloc(sizeof(ptr) * 512);
	ptr2 = (char *)malloc(sizeof(ptr2) * 512);
	while (bytes > 0)
	{
		bytes = read(0, ptr, 512);
		j = 0;
		while (ptr[j] != '\n' && bytes != 0)
		{
			ptr2[i] = ptr[j];
			i++;
			j++;
		}
		if (ptr2[i] == '\0' && bytes != 0)
		{
			ptr2[i] = '\n';
			i++;
			j++;
		}
		ptr2[i + 1] = '\0';
		ft_legend(ptr2);
	}
	return (ptr2);
}

int			main(int argc, char **argv)
{
	int		i;


	i = 0;
	if (argc < 2)
	{
		ft_legend(ft_get_input());
	}
	if (argc > 1)
		ft_enter_map(argv[i]);
	return (0);
}
