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

int		find_min(t_list **a)
{
	t_list	*current;
	int		min;

	min = (*a)->val;
	current = (*a)->next;
	while (current != *a)
	{
		if (current->val < min)
			min = current->val;
		current = current->next;
	}
	return (min);
}

int		find_max(t_list **a)
{
	t_list	*current;
	int		max;

	max = (*a)->val;
	current = (*a)->next;
	while (current != *a)
	{
		if (current->val > max)
			max = current->val;
		current = current->next;
	}
	return (max);
}

int		is_sorted(t_list **a, t_list **b)
{
	t_list	*current;

	if (*b != NULL)
		return (0);
	current = *a;
	while (current->next != *a)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

int		sorting(t_list **a, t_list **b)
{
	*a = NULL;
	*b = NULL;
	return (1);
}


int		main(int argc, char **argv)
{
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &a) == 0 || sorting(&a, &b) == 0)
		return (-1);
	return (1);
}
