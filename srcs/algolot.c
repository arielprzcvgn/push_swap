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

t_move	*fill(int total, int move_a, int move_b, int sens)
{
	t_move	*ret;

	ret = NULL;
	if ((ret = malloc(sizeof(ret))) == NULL)
		return (NULL);
	if (!(ret->total = (int)malloc(sizeof(ret->total))))
		return (NULL);
	if (!(ret->move_a = (int)malloc(sizeof(ret->move_a))))
		return (NULL);
	if (!(ret->move_b = (int)malloc(sizeof(ret->move_b))))
		return (NULL);
	if (!(ret->sens_a = (int)malloc(sizeof(ret->sens_a))))
		return (NULL);
	if (!(ret->sens_b = (int)malloc(sizeof(ret->sens_b))))
		return (NULL);
	ret->total = total;
	ret->move_a = move_a;
	ret->move_b = move_b;
	ret->sens_a = sens / 10 ? 1 : -1;
	ret->sens_b = sens % 10 ? 1 : -1;
	return (ret);
}

t_move	*procedure(int anext, int aprev, int bnext, int bprev)
{
	t_move	*m;
	int		anbp;
	int		apbn;
	int		abp;
	int		abn;

	m = NULL;
	anbp = anext + bprev;
	apbn = bnext + aprev;
	abp = aprev < bprev ? bprev : aprev;
	abn = anext < bnext ? bnext : anext;
	if (abn <= anbp && abn <= apbn && abn <= abp)
		m = fill(abn, anext, bnext, 11);
	else if (abp <= anbp && abp <= apbn && abp <= abn)
		m = fill(abp, aprev, bprev, 0);
	else if (anbp <= apbn && anbp <= abp && anbp <= abn)
		m = fill(anbp, anext, bprev, 10);
	else if (apbn <= anbp && apbn <= abp && apbn <= abn)
		m = fill(apbn, aprev, bnext, 1);
	return (m);
}

t_move	*nb_moves(t_list **a, t_list **b, t_list *to_move)
{
	t_list	*current;
	int		anext;
	int		aprev;
	int		bnext;
	int		bprev;

	anext = length(a, to_move, 1);
	aprev = length(a, to_move, -1);
	bnext = 0;
	bprev = 0;
	current = *b;
	while (current && ((current->val > current->prev->val &&
	(current->prev->val < to_move->val && to_move->val < current->val)) ||
	(current->val < current->prev->val &&
	(to_move->val < current->val || current->prev->val < to_move->val))) &&
	(++bnext))
		current = current->next;
	current = *b;
	while (current && ((current->val > current->prev->val &&
	(current->prev->val < to_move->val && to_move->val < current->val)) ||
	(current->val < current->prev->val &&
	(to_move->val < current->val || current->prev->val < to_move->val))) &&
	(++bprev))
		current = current->prev;
	return (procedure(anext, aprev, bnext, bprev));
}

int		how_to_step(t_list **a, t_list **b, t_list *step)
{
	t_move	*m;

	m = nb_moves(a, b, step);
	while (m->sens_a == m->sens_b && m->move_a && m->move_b)
	{
		m->move_a--;
		m->move_b--;
		rotate(a, m->sens_a);
		rotate(b, m->sens_b);
		ft_printf(m->sens_a == 1 ? "rr\n" : "rrr\n");
	}
	while (m->move_a-- && ft_printf(m->sens_a == 1 ? "ra\n" : "rra\n"))
		rotate(a, m->sens_a);
	while (m->move_b-- && ft_printf(m->sens_b == 1 ? "rb\n" : "rrb\n"))
		rotate(b, m->sens_b);
	push(a, b);
	ft_printf("pb\n");
	free(m);
	return (1);
}

int		algolot(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*step;
	t_move	*m;
	int		minimove;
	
	if (*a)
	{
		current = *a;
		m = nb_moves(a, b, current);
		minimove = m->total;
		step = current;
		while (current)
		{
			m = nb_moves(a, b, current);
			if (m->total < minimove && (step = current))
				minimove = m->total;
			current = current->next;
		}
		free(m);
		how_to_step(a, b, step);
		return (algolot(a, b));
	}
	while ((*b)->val < (*b)->prev->val && ft_printf("rb\n"))
		rotate(b, 1);
	while (*b && ft_printf("pa\n"))
		push(b, a);
	return (1);
}
