/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:18:28 by supersko          #+#    #+#             */
/*   Updated: 2022/03/17 11:38:14 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int ft_strlen(char *s)
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

void	ft_bzero(void *b, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = b;
	i = 0;
	while (i++ < n)
		*dest++ = 0;
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (!(mem = malloc(nmemb * size)))
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return (mem);
}

char	*ft_lst_to_str(t_list *item)
{
	size_t	len;
	char	*ret;
	t_list	*to_delete;

	len = ft_lstsize(item);
	ret = calloc(len, BUFFER_SIZE);
	if (!ret)
		return (NULL);
	while (item != NULL)
	{
		ft_strlcat(ret, item->line, BUFFER_SIZE);
		to_delete = item;
		item = item->next;
		ft_lstdelone(&to_delete);
	}
	return (ret);
}


char	*get_next_line(int fd)
{
	t_list		*str_link;
	t_list		*new_str_link;
	char		c;
	size_t		ii;

	if (fd == -1)
		return (NULL);
	str_link = ft_lstnew((char *) ft_calloc(1, sizeof(BUFFER_SIZE)));
	if (!str_link)
		return (NULL);
	if (BUFFER_SIZE != 0)
	{
		ii = 0;
		while (0 < read(fd, &c, 1))
		{
			if (c == '\n')
				return (ft_lst_to_str(str_link));
			else if (c == 0)
				return (ft_lst_to_str(str_link));
			else if (ii < BUFFER_SIZE - 1)
				str_link->line[ii++] = c;
			else
			{
				new_str_link = ft_lstnew(malloc(sizeof(BUFFER_SIZE)));
				if (new_str_link == NULL)
					return (NULL);
				new_str_link->next = str_link;
				str_link = new_str_link;
				ii = 0;
			}
		}
	}
	return (NULL);
}

int main(int argc, char *argv[])
{
	/*
	t_list	*n0;

	n0 = ft_lstnew("voici une chaine");
	ft_lstadd_back(&n0, ft_lstnew("une seconde"));
	ft_lstadd_back(&n0, ft_lstnew("\n"));
	printf("%s\n", ft_lst_to_str(n0));
	*/
	int fd;
	char	*line;
	int ii = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			line = get_next_line(fd);
			while (line != NULL)
			{
				printf("ligne %d: %s\n", ii++, line);
				line = get_next_line(fd);
			}
		}
	}
	else
	{
		printf("%s\n", "fichier manquant");
	}
	return (0);
}
