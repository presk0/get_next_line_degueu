/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:18:28 by supersko          #+#    #+#             */
/*   Updated: 2022/03/16 16:14:38 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int ft_strlen(char *s)
{
    unsigned int    ii;

    ii = 0;
    while (s[ii])
        ii++;
    return (ii);
}

size_t ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}

size_t  ft_strlcat(char *dst, char *src, size_t dstsize)
{
    size_t  dstr_len;

    dstr_len = ft_strlen(dst);
    if (dstr_len == dstsize)
        return (dstr_len + ft_strlen(src));
    return (dstr_len + ft_strlcpy(dst + dstr_len,
            (char *) src, dstsize - dstr_len));
}

char	*ft_lst_to_str(t_list *item)
{
	size_t	len;
	char	*ret;

	len = ft_lstsize(item);
	len *= (BUFFER_SIZE - len + 1);
	ret = malloc(len);
	if (!ret)
		return (NULL);
	while (item != NULL)
	{
		ft_strlcat(ret, item->line, len);
		item = item->next;
	}
	return (ret);
}

/*
char	*get_next_line(int fd)
{
	t_list		*str_link;
	t_list		*new_str_link;
	char		c;
	size_t		ii;

	if (fd != -1)
	{
		str_link = ft_lstnew(malloc(sizeof(BUFFER_SIZE)));
		if (!str_link)
			return (NULL);
		if (BUFFER_SIZE != 0)
			while (c && c != '\n')
			{
				if (-1 != read(fd, &c, 1))
				{
					if (ii < BUFFER_SIZE - 1)
						str_link->line[ii] = c;
					else
					{
						str_link->line[ii] = '\0';
						new_str_link = ft_lstnew(malloc(sizeof(BUFFER_SIZE)));
						if (!new_str_link)
							ft_lstclear(&str_link, free)
						new_str_link->next = str_link;
						str_link = new_str_link;
						ii = 0;
					}
				}
			}
	}
}
*/

int main(void) //int argc, *char[] argv)
{
	t_list	*n0;

	n0 = ft_lstnew("voici une chaine");
	ft_lstadd_back(&n0, ft_lstnew("une seconde"));
	printf("%s\n", ft_lst_to_str(n0));

	/*
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
	*/
}
