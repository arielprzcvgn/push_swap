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

t_list	*findmed(t_list **pile, t_list *part)
{
	t_list	*current;
	t_list	*test;
	int		top;
	int		bot;

	current = *pile;
	while (current != part)
	{
		top = 0;
		bot = 0;
		test = current->next;
		while (test != current)
		{
			if (current->content < test->content)
				top++;
			if (current->content > test->content)
				bot++;
			test = test->next;
			if (test == part)
				test = *pile;
		}
		if (0 <= top - bot && top - bot <= 1)
			return (current);
		current = current->next;
	}
	return (NULL);
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

t_list	*partition(t_list **pile, t_list **to_push, t_list *pivot, t_list *part, int a)
{
	t_list	*current;
	int		stop;

	while (a == -1 && *pile && findpivot(pile, a) == NULL &&
	findpivot(to_push, -a) == NULL)
	{
		push(pile, to_push);
		write(1, "pa\n", 3);
	}
	if (pivot == NULL)
		return (NULL);
	current = *pile;
	stop = (*pile)->prev->content;
	//printf("Pivot : %i\n", pivot->content);
	while (current->content != part->content)
	{
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
		//write(1, (a == 1? "Normal \n" : "Reverse\n"), 8);
		//visu(pile, to_push);
	}
	return (*to_push);
}

void	quick(t_list **pilea, t_list **pileb, t_list *part, int a)
{
	if (is_sorted(pilea, pileb) != 1)
	{
		if (a == 1 && (part = partition(pilea, pileb, findmed(pilea, part), part, a)))
		{
			quick(pilea, pileb, (*pilea)->prev, 1);
			//printf("A %i\n", part->content);
			quick(pilea, pileb, part, -1);
		}
		if (a == -1 && (part = partition(pileb, pilea, findmed(pileb, part), part, a)))
		{
			quick(pilea, pileb, (*pileb)->prev, -1);
			exit(0);
			//printf("B %i\n", part->content);
			quick(pilea, pileb, part, 1);
		}
	}
}