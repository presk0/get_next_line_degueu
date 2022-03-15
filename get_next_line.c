/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:18:28 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 20:21:53 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void	*buff[BUFFER_SIZE];
	size_t	len_read;

	len_read = 0;
	if (fd != -1)
	{
		read(fd, buff, BUFFER_SIZE);
		while ('\n' != (char)*buff && *buff)
		{
			len_read++;
			buff++;
		}
		la_ou_on_en_est += len_read
	}
}

int main(int argc, *char[] argv)
{
	int fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
			printf("%s\n", get_next_line(fd));
	}
	else
	{
		printf("%s\n", get_next_line(fd));
	}
	return (0);
}
