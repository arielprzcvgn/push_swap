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

t_move	*fill(int total, int move_a, int move_b, int sens_a, int sens_b)
{
	t_move	*ret;

	if ((ret = malloc(sizeof(ret))) == NULL)
		return (NULL);
	ret->total = total;
	ret->move_a = move_a;
	ret->move_b = move_b;
	ret->sens_a = sens_a;
	ret->sens_b = sens_b;
	return (ret);
}

t_move	*procedure(int anext, int aprev, int bnext, int bprev)
{
	t_move	*lemouv;
	int		anbp;
	int		apbn;
	int		abp;
	int		abn;
	
	lemouv = NULL;
	anbp = anext + bprev;
	apbn = bnext + aprev;
	abp = MAX(aprev, bprev);
	abn = MAX(anext, bnext);
	if (anbp <= apbn && anbp <= abp && anbp <= abn)
		lemouv = fill(anbp, anext, bprev, 1, -1);
	else if (apbn <= anbp && apbn <= abp && apbn <= abn)
		lemouv = fill(apbn, aprev, bnext, -1, 1);
	else if (abp <= anbp && abp <= apbn && abp <= abn)
		lemouv = fill(abp, aprev, bprev, -1, -1);
	else if (abn <= anbp && abn <= apbn && abn <= abp)
		lemouv = fill(abn, anext, bnext, 1, 1);
	return (lemouv);
}

t_move	*nb_moves(t_list **a, t_list **b, t_list *to_move)
{
	t_list	*current;
	int		anext;
	int		aprev;
	int		bnext;
	int		bprev;

	anext =	length(a, to_move, 1);
	aprev = length(a, to_move, -1);
	current = *b;
	bnext = 0;
	while (current && to_move->val < current->val &&
			to_move->val > current->prev->val && (++bnext))
		current = current->next;
	current = *b;
	bprev = 0;
	while (current && to_move->val < current->val &&
			to_move->val > current->prev->val && (++bprev))
		current = current->prev;
	return (procedure(anext, aprev, bnext, bprev));
}

int		how_to_step(t_list **a, t_list **b, t_list *step)
{
	t_move	*lemouv;
	
	lemouv = nb_moves(a, b, step);
	while (lemouv->move_a--)
	{
		rotate(a, lemouv->sens_a);
		ft_printf(lemouv->sens_a == 1 ? "ra\n" : "rra\n");
	}
	while (lemouv->move_b--)
	{
		rotate(b, lemouv->sens_b);
		ft_printf(lemouv->sens_b == 1 ? "rb\n" : "rrb\n");
	}
	push(a, b);
	ft_printf("pb\n");
	return (1);
}

int		algolot(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*step;
	t_move	*move;
	int		minimove;

	if (*a)
	{
		current = *a;
		move = nb_moves(a, b, current);
		minimove = move->total;
		step = current;
		while (current)
		{
			move = nb_moves(a, b, current);
			if (move->total < minimove)
				step = current;
			current = current->next;
		}
		how_to_step(a, b, step);
		return (algolot(a, b));
	}
	while (*b)
	{
		push(b, a);
		ft_printf("pa\n");
	}
	return (1);
}