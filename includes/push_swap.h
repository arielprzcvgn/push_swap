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

# define BUFF_SIZE 500

typedef struct		s_list
{
	int				content;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

/*
**Initialisation (init.c)
*/
t_list				*ps_lstnew(t_list **list, int content);
int					ps_lstadd(t_list **list, int content);
int					ps_atoi(const char *str, t_list **pilea);
int					ps_init(int argc, char **argv, t_list **pilea);

/*
**Possible operations (operation.c)
*/
int					swap(t_list **list);
int					push(t_list **listfrom, t_list **listto);
int					rotate(t_list **list, int rev);
int					notanop();
int					chooseop(char *op, t_list **pilea, t_list **pileb);

/*
**Visualisation (visu.c)
*/
int					visu(t_list **pilea, t_list **pileb);

/*
**Sort (push_swap.c)
*/
int					is_sorted(t_list **pilea);
int					get_instructions(t_list **pilea);

/*
**Bubble (bubble.c)
*/
int					bubble(t_list **pilea);


/*
**libft
*/
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strlen(const char *s);
void				ft_strclr(char *s);
char				*ft_strjoinfree(char *s1, char *s2, int frees1, int frees2);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_bzero(void *b, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);

#endif
