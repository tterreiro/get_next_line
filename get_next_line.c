/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-andr <hde-andr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:48 by hde-andr          #+#    #+#             */
/*   Updated: 2025/11/03 20:11:46 by hde-andr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **buffer)
{
	char	*line;
	char	*rest;
	size_t	new_line;
	size_t	end_of_file;

	new_line = ft_strlen(*buffer, '\n');
	if ((*buffer)[new_line] == '\n')
		new_line++;
	line = ft_strndup(*buffer, new_line);
	if (!line)
		return (NULL);
	end_of_file = ft_strlen(*buffer + new_line, '\0');
	rest = ft_strndup(*buffer + new_line, end_of_file);
	if (!rest)
	{
		free (line);
		return (NULL);
	}
	free (*buffer);
	*buffer = rest;
	return (line);
}

static char	*get_buffer(int fd, char *buffer)
{
	char	*current;
	size_t	bytes;

	bytes = 1;
	current = malloc(BUFFER_SIZE + 1);
	if (!current)
		return (NULL);
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read (fd, current, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
		{
			free (current);
			return (NULL);
		}
		current[bytes] = '\0';
		buffer = merge(buffer, current);
	}
	free(current);
	if (ft_strlen(buffer, '\0') > 0)
		return (buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(&buffer);
	if (!buffer[0])
	{
		free (buffer);
		buffer = NULL;
	}
	return (line);
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