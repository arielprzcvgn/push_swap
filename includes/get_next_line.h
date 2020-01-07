/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:07:48 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/04 15:58:18 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "push_swap.h"

typedef struct		s_fd
{
	void			*buf;
	size_t			fd;
	int				red;
	struct s_fd		*next;
}					t_fd;

int					get_next_line(const int fd, char **line);

#endif
