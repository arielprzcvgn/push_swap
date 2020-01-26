/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algolot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		length(t_list **list, t_list *stop, int	way)
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

int		nb_moves(t_list **a, t_list **b, t_list *to_move)
{
	t_list	*current;
	int		movea;
	int		moveb;

	movea = (length(a, to_move, 1) < length(a, to_move, -1)?
			length(a, to_move, 1) : length(a, to_move, -1));
	current = *b;
	moveb = 0;
	while (current && current->val > to_move->val && (++moveb))
		current = current->next;
	if (length(b, NULL, 1) - moveb < moveb)
	{
		current = *b;
		moveb = 0;
		while (current && current->val > to_move->val && (++moveb))
			current = current->prev;
	}
	//opti des rr, mieux de forcer un sens pour 1 pile pour en utiliser
	return (movea + moveb);
}

int		how_to_step(t_list **a, t_list **b, t_list *step)
{
	t_list	*current;
	int		movea;
	int		moveb;
	int		sensa;
	int		sensb;
	
	movea = (length(a, step, 1) < length(a, step, -1) ?
		length(a, step, (sensa = 1)) : length(a, step, (sensa = -1)));
	current = *b;
	moveb = 0;
	sensb = 1;
	while (current && current->val > step->val && (++moveb))
		current = current->next;
	if (length(b, NULL, 1) - moveb < moveb)
	{
		current = *b;
		moveb = 0;
		sensb = -1;
		while (current && current->val > step->val && (++moveb))
			current = current->prev;
	}
}

int		algolot(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*step;
	int		minimove;

	if (a)
	{
		current = *a;
		minimove = nb_moves(a, b, current);
		step = current;
		while (current)
		{
			if (nb_moves(a, b, current) < minimove)
				step = current;
			current = current->next;
		}
		how_to_step(a, b, step);
		return (algolot(a, b));
	}
	while (b)
		push(b, a);
	return (1);
}