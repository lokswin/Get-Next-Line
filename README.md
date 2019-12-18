##Get_Next_Line
	
	Get Next Line(GNL)
 	Function to read one line from file, which ends with a line break.
SYNOPSIS

	#include "libft\libft.h"
 
	int get_next_line(const int fd, char **line)
 
DESCRIPTION

	INPUT
		char **line - pointer to memory area which store result;
		const int fd - file descriptor to be read;
		
	OUTPUT
		One line without '\n';
	
RETURN VALUES

	0 when no more lines to be read;
	1 when reading end successfully;
	-1 when error occurs;
	
EXTRAS

	You can change buffer size for GNL (1-9999). For this put your BUFF_SIZE number in "get_next_line.h" file.
```get_next_line.h
	...
# define BUFF_SIZE 9999
	...
```
	Buffer size should not be more then 9999, as the behavior is undefined.
