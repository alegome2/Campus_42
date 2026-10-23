/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegome2 <alegome2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:42:54 by alegome2          #+#    #+#             */
/*   Updated: 2026/10/23 12:21:42 by alegome2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer_temp;
	int		bytes_read;
	char	*temp;

	buffer_temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer_temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (free(buffer_temp), NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer_temp[bytes_read] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buffer_temp);
		free(temp);
	}
	return (free(buffer_temp), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
}
