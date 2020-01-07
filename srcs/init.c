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

t_list	*ps_lstnew(t_list **list, int content)
{
	t_list	*new;

	new = NULL;
	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = (int)malloc(sizeof(content))))
		return (NULL);
	new->content = content;
	new->prev = NULL;
	new->next = NULL;
	if (*list == NULL)
		*list = new;
	return (new);
}

int		ps_lstadd(t_list **list, int content)
{
	t_list	*new;
	t_list	*current;

	if ((new = ps_lstnew(list, content)) == NULL)
		return (0);
	current = *list;
	while (current)
	{
		if (current->content == content)
		{
			write(2, "Duplicate\n", 10);
			return (0);
		}
		new->prev = current;
		current = current->next;
	}
	new->prev->next = new;
	return (1);
}

int		ps_atoi(const char *str, t_list **pilea)
{
	int		i;
	int		negative;
	int		number;
	long	farfromint;

	i = 0;
	farfromint = 0;
	negative = 1;
	if (str[i] == '+' || str[i] == '-')
		negative = (str[i++] == '-') ? -1 : 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		farfromint = farfromint * 10;
		farfromint += (str[i] - '0');
		i++;
	}
	number = negative * farfromint;
	if (((str[i] && (str[i] < '0' || '9' < str[i])) ||
		(number != negative * farfromint || ft_strlen(str) > 12)) &&
		write(2, "Invalid argument\n", 18))
		return (0);
	if (*pilea == NULL)
		return (ps_lstnew(pilea, number) ? 1 : 0);
	return (ps_lstadd(pilea, number));
}

int		ps_init(int argc, char **argv, t_list **pilea)
{
	int		i;
	t_list	*current;

	i = 0;
	if (argc == 2)
	{
		argv = ft_strsplit(argv[1], ' ');
		i = -1;
	}
	while (argv[++i])
	{
		if (!*argv[i] || ps_atoi(argv[i], pilea) == 0)
		{
			write(2, "Error atoi\n", 6);
			return (0);
		}
	}
	current = *pilea;
	while (current->next != NULL)
		current = current->next;
	current->next = *pilea;
	(*pilea)->prev = current;
	return (1);
}
