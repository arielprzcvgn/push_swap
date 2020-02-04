/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ps_lstnew(t_list **list, int val)
{
	t_list	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->val = (int)malloc(sizeof(val))))
		return (NULL);
	new->val = val;
	new->prev = NULL;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	return (new);
}

int		ps_lstadd(t_list **list, int val)
{
	t_list	*new;
	t_list	*current;

	if ((new = ps_lstnew(list, val)) == NULL)
		return (0);
	current = *list;
	while (current)
	{
		if (current->val == val && ft_printf("Duplicate\n"))
			return (0);
		new->prev = current;
		current = current->next;
	}
	new->prev->next = new;
	return (1);
}

int		ps_atoi(const char *str, t_list **a)
{
	int		i;
	int		neg;
	int		nbr;
	long	farfromint;

	i = 0;
	farfromint = 0;
	neg = 1;
	if (str[i] == '+' || str[i] == '-')
		neg = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		farfromint = farfromint * 10;
		farfromint += (str[i] - '0');
		i++;
	}
	nbr = neg * farfromint;
	if (((str[i] && (str[i] < '0' || '9' < str[i])) ||
		(nbr != neg * farfromint || ft_strlen(str) > 12)) &&
		ft_printf("Invalid argument\n"))
		return (0);
	if (*a == NULL)
		return (ps_lstnew(a, nbr) ? 1 : 0);
	return (ps_lstadd(a, nbr));
}

int		options(char *opt, t_opt *o)
{
	int		i;

	i = 0;
	while(opt[++i])
	{
		if (opt[i] == 'c')
			o->color = 1;
		else if (opt[i] == 'v')
			o->visu = 1;
		else
			ft_printf("Unknown option. Ignored.\n");
	}
	return (1);
}

int		ps_init(int argc, char **argv, t_list **a, t_opt *o)
{
	int		i;
	t_list	*current;

	i = 0;
	if (o && (!(o->visu = (int)malloc(sizeof(o->visu))) || (o->visu = 0) ||
	!(o->color = (int)malloc(sizeof(o->color))) || (o->color = 0) ||
	!(o->len = (int)malloc(sizeof(o->color))) || (o->len = 10)))
		return (0);
	visu(a, a, o);
	while (o && argv[++i][0] == '-')
		options(argv[i], o);
	visu(a, a, o);
	if (i == argc - 1 && !(i = 0))
		argv = ft_strsplit(argv[argc - 1], ' ');
	while (argv[i])
	{
		if ((!*argv[i] || ps_atoi(argv[i], a) == 0) &&
		ft_printf("Error atoi\n"))
			return (0);
		i++;
	}
	current = *a;
	while (current->next)
		current = current->next;
	(*a)->prev = current;
	return (1);
}
