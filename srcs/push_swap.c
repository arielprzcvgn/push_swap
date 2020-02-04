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

int		length(t_list **list, t_list *stop, int way)
{
	t_list	*current;
	int		len;

	len = 0;
	current = *list;
	while (way == 1 && current && current != stop && (++len))
		current = current->next;
	while (way == -1 && current && current != stop && (++len))
		current = current->prev;
	return (len);
}

int		is_sorted(t_list **a, t_list **b)
{
	t_list	*current;

	if (*b != NULL)
		return (0);
	current = *a;
	while (current->next)
	{
		if (current->val > current->next->val)
			return (0);
		current = current->next;
	}
	return (1);
}

int		sorting(t_list **a, t_list **b)
{
	//if (length(a, NULL, 1) <= 5)
	//	highlgofive(a, b);
	//else
	algolot(a, b);
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
	if (ps_init(argc, argv, &a, NULL) == 0 || sorting(&a, &b) == 0)
		return (-1);
	return (1);
}
