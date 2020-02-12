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
	if (!(ret = malloc(sizeof(t_move))))
		return (NULL);
	ret->total = total;
	ret->move_a = move_a;
	ret->move_b = move_b;
	ret->sens_a = sens / 10 ? 1 : -1;
	ret->sens_b = sens % 10 ? 1 : -1;
	return (ret);
}

t_move	*optimove(int anext, int aprev, int bnext, int bprev)
{
	int		anbp;
	int		apbn;
	int		abp;
	int		abn;

	anbp = anext + bprev;
	apbn = bnext + aprev;
	abp = aprev < bprev ? bprev : aprev;
	abn = anext < bnext ? bnext : anext;
	if (abn <= anbp && abn <= apbn && abn <= abp)
		return (fill(abn, anext, bnext, 11));
	else if (abp <= anbp && abp <= apbn && abp <= abn)
		return (fill(abp, aprev, bprev, 0));
	else if (anbp <= apbn && anbp <= abp && anbp <= abn)
		return (fill(anbp, anext, bprev, 10));
	else if (apbn <= anbp && apbn <= abp && apbn <= abn)
		return (fill(apbn, aprev, bnext, 1));
	return (NULL);
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
	return (optimove(anext, aprev, bnext, bprev));
}

int		how_to_step(t_list **a, t_list **b, t_list *step)
{
	t_move	*m;

	if (!(m = nb_moves(a, b, step)))
		return (free_deb_hug(a, b, NULL, 1));
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
	if (m)
		free(m);
	return (1);
}

int		algolot(t_list **a, t_list **b)
{
	t_list	*current;
	t_list	*step;
	t_move	*m;
	int		minimove;

	while (*a && (current = *a))
	{
		minimove = -1;
		while (current)
		{
			if (!(m = nb_moves(a, b, current)))
				return (free_deb_hug(a, b, NULL, 1));
			if ((m->total < minimove || minimove == -1) && (step = current))
				minimove = m->total;
			free(m);
			current = current->next;
		}
		if (!(how_to_step(a, b, step)))
			return (free_deb_hug(a, b, NULL, 1));
	}
	while ((*b)->val < (*b)->prev->val && ft_printf("rb\n"))
		rotate(b, 1);
	while (*b && ft_printf("pa\n"))
		push(b, a);
	return (1);
}
