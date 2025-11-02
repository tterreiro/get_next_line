/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-andr <hde-andr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:54:02 by hde-andr          #+#    #+#             */
/*   Updated: 2025/11/02 17:16:17 by hde-andr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (src == NULL && dest == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i++;
	}
	if (chr == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (s[i] && i < len)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*merge(char	*prev, const char *current)
{
	size_t	len_prev;
	size_t	len_cur;
	char	*merged;

	if (prev)
		ft_strlen(prev);
	len_cur = ft_strlen(current);
	merged = malloc(len_cur + len_prev + 1);
	if (!merged)
		return (NULL);
	if (prev)
		ft_memcpy(merge, prev, len_prev);
	ft_memcpy(merge + len_prev, current, len_cur);
	merged[len_cur + len_prev + 1] = '\0';
	if (prev)
		free (prev);
	return (merged);
}
