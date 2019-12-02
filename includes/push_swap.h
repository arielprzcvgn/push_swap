/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:54 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:09:19 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h> //DEBUG

# define BUFF_SIZE 5

typedef struct		s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *s);
void				ft_strclr(char *s);

/*
**Initialisation (init.c)
*/
t_list				*ps_lstnew(t_list **list,int content);
int					ps_lstadd(t_list **list, int content);
int					ps_atoi(const char *str, t_list **pileA);
int					ps_init(int argc, char **argv, t_list **pileA);

/*
**Possible operations (operation.c)
*/
int					swap(t_list **list);
int					push(t_list **listfrom, t_list **listto);
int					rotate(t_list **list, int rev);
int					notanop();
int					chooseop(char *op, t_list **pileA, t_list **pileB);

/*
**Visualisation (visu.c)
*/
int					visu(t_list **pileA, t_list **pileB);

#endif