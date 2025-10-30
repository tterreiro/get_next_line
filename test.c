#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	lala(int fd)
{
	char	stack[1231];
	read(fd, stack, sizeof(stack));
	printf("%s", stack);
}

int	main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	lala(fd);
	return 0;
}