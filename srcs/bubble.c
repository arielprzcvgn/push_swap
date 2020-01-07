/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
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

int		bubble(t_list **pilea)
{
	t_list	*current;
	int		swap;
	int		min;

	min = find_min(pilea);
	while (is_sorted(pilea) != 1)
	{
		current = *pilea;
		if (current->content > current->next->content &&
			current->next->content != min)
		{
			swap = current->content;
			current->content = current->next->content;
			current->next->content = swap;
			write(1, "sa\n", 3);
		}
		if (is_sorted(pilea) != 1)
		{
			*pilea = (*pilea)->prev;
			write(1, "rra\n", 4);
		}
	}
	return (1);
}
