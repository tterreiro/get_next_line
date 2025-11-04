/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-andr <hde-andr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:48 by hde-andr          #+#    #+#             */
/*   Updated: 2025/11/04 18:24:51 by hde-andr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

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
	{
		free (*buffer);
		return (NULL);
	}
	end_of_file = ft_strlen(*buffer + new_line, '\0');
	rest = ft_strndup(*buffer + new_line, end_of_file);
	if (!rest)
	{
		free (line);
		free (*buffer);
		return (NULL);
	}
	free (*buffer);
	*buffer = rest;
	return (line);
}

static char	*get_buffer(int fd, char *buffer)
{
	char	*current;
	ssize_t	bytes;

	bytes = 1;
	current = malloc(BUFFER_SIZE + 1);
	if (!current)
		return (ft_free(buffer));
	while (bytes > 0)
	{
		bytes = read (fd, current, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		current[bytes] = '\0';
		buffer = merge(buffer, current);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(current);
	if (bytes < 0 || ft_strlen(buffer, '\0') <= 0)
		return (ft_free(buffer));
	return (buffer);
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
	if (!line)
	{
		buffer = NULL;
		return (NULL);
	}
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