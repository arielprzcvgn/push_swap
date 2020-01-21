/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:46:18 by ariperez          #+#    #+#             */
/*   Updated: 2019/12/12 18:46:23 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_min(t_list **pilea)
{
	t_list	*current;
	int		min;

	min = (*pilea)->content;
	current = (*pilea)->next;
	while (current != *pilea)
	{
		if (current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

int		find_max(t_list **pilea)
{
	t_list	*current;
	int		max;

	max = (*pilea)->content;
	current = (*pilea)->next;
	while (current != *pilea)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int		is_sorted(t_list **pilea, t_list **pileb)
{
	t_list	*current;

	if (*pileb != NULL)
		return (0);
	current = *pilea;
	while (current->next != *pilea)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int		sorting(t_list **pilea, t_list **pileb)
{
	//perso(pilea, pileb, 1);
	quick(pilea, pileb, (*pilea)->prev, 1);
	//bubble(pilea, pileb);
	return (1);
}


int		main(int argc, char **argv)
{
	t_list		*pilea;
	t_list		*pileb;

	pilea = NULL;
	pileb = NULL;
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &pilea) == 0 || sorting(&pilea, &pileb) == 0)
		return (-1);
	return (1);
}
