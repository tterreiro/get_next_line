/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-andr <hde-andr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:48 by hde-andr          #+#    #+#             */
/*   Updated: 2025/11/02 17:23:17 by hde-andr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer)
{
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = 
}

/* int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		char *str = get_next_line(fd);
		printf("%s", get_next_line(fd));
	}
} */