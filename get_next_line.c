/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:17:56 by supersko          #+#    #+#             */
/*   Updated: 2022/04/07 16:26:34 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		len;

	len = 0;
	line = NULL;
	while (1)
	{
		if (read(fd, &c, 1) > 0)
			line = ft_realloc_cat(line, c, &len);
		else
			(c = '\0');
		if (c == '\n' || !c)
			return (line);
	}
	if (line)
		free(line);
	return (NULL);
}

/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	(void)argc;
	if (!argv[1])
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close(fd);
}
*/
