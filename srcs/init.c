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

	if (!(new = malloc(sizeof(t_list))))
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

	if (!(new = ps_lstnew(list, val)))
		return (0);
	current = *list;
	while (current)
	{
		if (current->val == val)
		{
			free(new);
			return (0);
		}
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
	if ((str[i] && (str[i] < '0' || '9' < str[i])) ||
		nbr != neg * farfromint || ft_strlen(str) > 12)
		return (0);
	if (*a == NULL)
		return (ps_lstnew(a, nbr) ? 1 : 0);
	return (ps_lstadd(a, nbr));
}

int		options(char *opt, t_opt *o)
{
	int		i;

	if (opt == NULL || opt[0] == 0 || *opt != '-' ||
	(opt[1] != 0 && '0' <= opt[1] && opt[1] <= '9'))
		return (0);
	i = 1;
	while (opt[i] && opt[i] != ' ')
	{
		if ((opt[i] == 'c' && (o->color = 1)) ||
		(opt[i] == 'v' && (o->visu = 1)) ||
		(opt[i] == 'd' && (o->debug = 1)))
			i++;
		else
		{
			ft_printf("checker: illegal option : %c\n", opt[i]);
			ft_printf("usage: ./checker [-dvc] [stack]\n");
			return (-1);
		}
	}
	return (1);
}

int		ps_init(int argc, char **argv, t_list **a, t_opt *o)
{
	int		i;
	char	**tab;
	t_list	*current;

	i = 1;
	while (o && i < argc && options(argv[i], o) == 1)
		i++;
	if (i == argc || argv[i][0] == 0 ||
	(i == argc - 1 && (tab = ft_strsplit(argv[i], ' ')) == NULL) ||
	(i < argc - 1 && (tab = copy_tab(tab, argv, argc, i)) == NULL))
		return (free_deb_hug(a, NULL, o, 1));
	i = 0;
	while (tab[i])
		if (!ps_atoi(tab[i++], a))
			return (free_deb_hug(a, NULL, o, 2));
	free_tab(tab);
	current = *a;
	while (current->next)
		current = current->next;
	(*a)->prev = current;
	return (1);
}
/*
int		ps_init(int argc, char **argv, t_list **a, t_opt *o)
{
	int		i;
	int		free_argv;
	t_list	*current;

	i = 1;
	free_argv = 0;
	while (o && i < argc && argv[i][0] == '-')
		options(argv[i++], o);
	if (i == argc - 1 && !(i = 0) &&
						(free_argv = 1))
		argv = ft_strsplit(argv[argc - 1], ' ');
	if (i == argc || !argv[i])
		return (free_deb_hug(a, NULL, o, 0));
	while (argv[i])
		if (!ps_atoi(argv[i++], a))
			return (free_deb_hug(a, NULL, o, 2));
	if (free_argv)
		free_tab(argv);
	current = *a;
	while (current->next)
		current = current->next;
	(*a)->prev = current;
	return (1);
}*/
