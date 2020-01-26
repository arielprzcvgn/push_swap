/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	visu(t_list **a, t_list **b)
{
	t_list	*current;

	ft_printf("Pile A |");
	current = *a;
	while (current)
	{
		ft_printf(" %i", current->val);
		current = current->next;
	}
	ft_printf("\nPile B | ");
	current = *b;
	while (current)
	{
		ft_printf(" %i", current->val);
		current = current->next;
	}
	ft_printf("\n");
}