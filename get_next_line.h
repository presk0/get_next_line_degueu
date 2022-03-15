/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:14:52 by supersko          #+#    #+#             */
/*   Updated: 2022/03/15 20:21:11 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifdef BUFFER_SIZE

#  include <sys/types.h>
#  include <sys/uio.h>
#  include <unistd.h>

#  include <stdio.h>
#  include <string.h>

static size_t la_ou_on_en_est = 0;

char *get_next_line(int fd);

# endif
#endif
