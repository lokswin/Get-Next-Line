
	Get Next Line
 	Function to read one line(\n) from file.
SYNOPSIS

	#include "libft\libft.h"
 
	int
	get_next_line(const int fd, char **line)
 
DESCRIPTION
	INPUT
	char **line - pointer to memory area which store result(one line);
	int fd - file descriptor to be read;
	OUTPUT
	One line without '\n';
	
RETURN VALUES
	0 when no more lines to be read;
	1 when reading end successfully;
	-1 when error occurs;
