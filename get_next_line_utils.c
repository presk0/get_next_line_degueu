/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:02:10 by supersko          #+#    #+#             */
/*   Updated: 2022/04/06 14:02:38 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc_cat(char *line, char c, int *len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *) malloc(*len + 2);
	if (!ret)
		return (NULL);
	while (i < *len && line)
	{
		ret[i] = line[i];
		i++;
	}
	ret[*len] = c;
	ret[++(*len)] = '\0';
	if (line)
		free(line);
	return (ret);
}
