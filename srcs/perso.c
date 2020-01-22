/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*findordered(t_list **pile, int a)
{
	t_list	*current;
	
	if (*pile == NULL)
		return (NULL);
	current = (*pile)->prev;
	while (current != *pile)
	{
		if (a * current->content < a * current->prev->content)
			return(current);
		current = current->prev;
	}
	return (NULL);
}

t_list	*part(t_list **pile, t_list **to_push, t_list *pivot, int a)
{
	t_list	*current;
	int		stop;

	while (a == -1 && *pile && findordered(pile, a) == NULL)
	{
		push(pile, to_push);
		write(1, "pa\n", 3);
	}
	if (pivot == NULL)
		return (NULL);
	current = *pile;
	stop = (*pile)->prev->content;
	//printf("%i\n", pivot->content);
	while (current != pivot)
	{
		if (a * current->content > a * current->next->content &&
		a * current->content < a * pivot->content)
		{
			swap(pile);
			write(1, (a == 1? "sa\n" : "sb\n"), 3);
		}
		if (a * current->content <= a * pivot->content)
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
		//write(1, (a == 1? " Normal\n" : "Reverse\n"), 8);
		//visu(pile, to_push);
	}
	return (findordered(pile, a));
}

void	perso(t_list **pilea, t_list **pileb, int a)
{
	if (is_sorted(pilea, pileb) != 1)
	{
		if (a == 1 && part(pilea, pileb, findordered(pilea, a), a))
		{
			perso(pilea, pileb, 1);
			perso(pilea, pileb, -1);
		}
		if (a == -1 && part(pileb, pilea, findordered(pileb, a), a))
		{
			perso(pilea, pileb, -1);
			perso(pilea, pileb, 1);
		}
	}
}