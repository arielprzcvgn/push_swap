/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*findpivot(t_list **pile)
{
	t_list	*current;
	
	current = (*pile)->prev;
	while (current != *pile)
	{
		if (current->content < current->prev->content)
			return(current);
		current = current->prev;
	}
	return (NULL);
}

t_list	*partition(t_list **pile, t_list **to_push, t_list *pivot, int a)
{
	t_list	*current;
	t_list	*next;

	next = NULL;
	current = *pile;
	while (current != pivot)
	{
		if (current->next == pivot)
			next = current;
		if (a * current->content > a * current->next->content)
		{
			swap(pile);
			write(1, (a == 1? "sa\n" : "sb\n"), 3);
		}
		if (a * current->content < a * pivot->content)
		{
			current = current->next;
			push(pile, to_push);
			write(1, (a == 1? "pb\n" : "pa\n"), 3);
		}
		else if (a * current->content > a * pivot->content)
		{
			current = current->next;
			rotate(pile, 0);
			write(1, (a == 1? "ra\n" : "rb\n"), 3);
		}
		//write(1, (a == 1? "Normal\n" : "Reverse\n"), 8);
		//visu(pile, to_push);
	}
	if (a == -1 && *pile == (*pile)->next)
	{
		push(pile, to_push);
		write(1, "pa\n", 3);
	}
	return (next);
}

void	quick(t_list **pilea, t_list **pileb, int a)
{
	if (findpivot(pilea))
	{
		if (a == 1 && partition(pilea, pileb, findpivot(pilea), a) != NULL)
		{
			quick(pilea, pileb, 1);
			quick(pilea, pileb, -1);
		}
		if (a == -1 && partition(pileb, pilea, (*pileb? (*pileb)->prev : NULL), a) != NULL)
		{
			quick(pilea, pileb, -1);
			quick(pilea, pileb, 1);
		}
	}
}