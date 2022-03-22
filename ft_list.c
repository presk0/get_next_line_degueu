/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:36:39 by supersko          #+#    #+#             */
/*   Updated: 2022/03/22 14:30:46 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_item;

	if (lst && del)
	{
		while (*lst)
		{
			next_item = (*lst)->next;
			ft_lstdelone(lst);
			*lst = next_item;
		}
	}
}

void	ft_lstdelone(t_list **lst)
{
	if (lst)
	{
		free((*lst)->line);
		free(*lst);
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buff;

	if (new)
	{
		buff = ft_lstlast(*lst);
		if (!buff)
			*lst = new;
		else
			buff->next = new;
	}
}


t_list	*ft_lstnew(char *line)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	unsigned int	len;

	if (lst == NULL)
		return (0);
	len = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
