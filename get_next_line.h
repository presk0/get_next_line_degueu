/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:14:52 by supersko          #+#    #+#             */
/*   Updated: 2022/03/16 16:07:44 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
//# ifdef BUFFER_SIZE

#  include <sys/types.h>
#  include <sys/uio.h>
#  include <unistd.h>

#  include <stdio.h>
#  include <string.h>
#  include <stdlib.h>
#  define BUFFER_SIZE 42

typedef struct s_list 
{
	char			*line;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(char *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int		ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);

//# endif
#endif
