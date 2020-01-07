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

//UTILISER MON PRINTF !!!

int		visu(t_list **pilea, t_list **pileb)
{
	t_list	*current;

	current = *pilea;
	printf("Pile A |");
	while (current && current->next != *pilea)
	{
		printf(" %i", current->content);
		current = current->next;
	}
	if (current)
		printf(" %i", current->content);
	printf("\n");
	current = *pileb;
	printf("Pile B |");
	while (current && current->next != *pileb)
	{
		printf(" %i", current->content);
		current = current->next;
	}
	if (current)
		printf(" %i", current->content);
	printf("\n");
	return (1);
}
