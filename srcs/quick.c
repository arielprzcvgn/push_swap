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

t_list	*findmed(t_list **pile)
{
	t_list	*current;
	t_list	*med;
	int		mediane;
	
	current = *pile;
	med = (*pile)->prev;
	mediane = (find_min(pile) + find_max(pile)) / 2;
	while (current != (*pile)->prev)
	{
		if (med->content < current->content && current->content <= mediane)
			med = current;
		current = current->next;
	}
	return (med);
}

t_list	*findpivot(t_list **pile, int a)
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

t_list	*partition(t_list **pile, t_list **to_push, t_list *pivot, int a)
{
	t_list	*current;
	int		stop;

	while (a == -1 && *pile && findpivot(pile, a) == NULL)
	{
		push(pile, to_push);
		write(1, "pa\n", 3);
	}
	if (pivot == NULL)
		return (NULL);
	current = *pile;
	stop = (*pile)->prev->content;
	//printf("%i\n", pivot->content);
	while (current->content != pivot->content)
	{
		if (a * current->content > a * current->next->content &&
		a * current->content < a * pivot->content)
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
	return (findpivot(pile, a));
}

void	quick(t_list **pilea, t_list **pileb, int a)
{
	if (is_sorted(pilea, pileb) != 1)
	{
		if (a == 1 && partition(pilea, pileb, findpivot(pilea, a), a))
		{
			quick(pilea, pileb, 1);
			quick(pilea, pileb, -1);
		}
		if (a == -1 && partition(pileb, pilea, findpivot(pileb, a), a))
		{
			quick(pilea, pileb, -1);
			quick(pilea, pileb, 1);
		}
	}
}