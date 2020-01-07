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

int		sort(t_list **pilea)
{
	t_list	*current;

	current = *pilea;
	while (current->next != *pilea)
	{
		if (current->content >= current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

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

char	*bubble(t_list **pilea, char *instructions)
{
	t_list	*current;
	int		swap;
	int		min;

	min = find_min(pilea);
	while (sort(pilea) != 1)
	{
		current = *pilea;
		if (current->content > current->next->content &&
			current->next->content != min)
		{
			swap = current->content;
			current->content = current->next->content;
			current->next->content = swap;
			ft_strcat(instructions, "sa\n");
		}
		if (sort(pilea) != 1)
		{
			*pilea = (*pilea)->prev;
			ft_strcat(instructions, "rra\n");
		}
	}
	return (instructions);
}
