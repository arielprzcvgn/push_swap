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

int		bubble(t_list **pilea, t_list **pileb)
{
	t_list	*current;
	int		min;

	min = find_min(pilea);
	while (is_sorted(pilea, pileb) != 1)
	{
		current = *pilea;
		if (current->content > current->next->content &&
			current->next->content != min)
		{
			swap(pilea);
			write(1, "sa\n", 3);
		}
		if (is_sorted(pilea, pileb) != 1)
		{
			rotate(pilea, 1);
			write(1, "rra\n", 4);
		}
	}
	return (1);
}
