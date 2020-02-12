/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlgofive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**bf2(t_list **a, t_list **b, int out, char **inst)
{
	if (rotate(a, 1) && (bf(a, b, out - 1, inst) || !rotate(a, -1)))
		*inst = ft_strjoinfree("ra\n", *inst, 0, 1);
	else if (rotate(b, 1) && (bf(a, b, out - 1, inst) || !rotate(b, -1)))
		*inst = ft_strjoinfree("rb\n", *inst, 0, 1);
	else if (rotate(a, 1) && (rotate(b, 1) || !rotate(a, -1)) &&
	(bf(a, b, out - 1, inst) || !rotate(a, -1) || !rotate(b, -1)))
		*inst = ft_strjoinfree("rr\n", *inst, 0, 1);
	else if (rotate(a, -1) && (bf(a, b, out - 1, inst) || !rotate(a, 1)))
		*inst = ft_strjoinfree("rra\n", *inst, 0, 1);
	else if (rotate(a, -1) && (bf(a, b, out - 1, inst) || !rotate(a, 1)))
		*inst = ft_strjoinfree("rrb\n", *inst, 0, 1);
	else if (rotate(a, -1) && (rotate(b, -1) || !rotate(a, 1)) &&
	(bf(a, b, out - 1, inst) || !rotate(a, 1) || !rotate(b, 1)))
		*inst = ft_strjoinfree("rrr\n", *inst, 0, 1);
	if (is_sorted(a, b))
		return (inst);
	return (NULL);
}

char	**bf(t_list **a, t_list **b, int out, char **inst)
{
	if (is_sorted(a, b))
		return (inst);
	if (out == 0)
		return (NULL);
	else if (swap(a) && (bf(a, b, out - 1, inst) || !swap(a)))
		*inst = ft_strjoinfree("sa\n", *inst, 0, 1);
	else if (swap(b) && (bf(a, b, out - 1, inst) || !swap(b)))
		*inst = ft_strjoinfree("sb\n", *inst, 0, 1);
	else if (swap(a) && (swap(b) || !swap(a)) &&
	(bf(a, b, out - 1, inst) || !swap(a) || !swap(b)))
		*inst = ft_strjoinfree("ss\n", *inst, 0, 1);
	else if (push(b, a) && (bf(a, b, out - 1, inst) || !push(a, b)))
		*inst = ft_strjoinfree("pa\n", *inst, 0, 1);
	else if (push(a, b) && (bf(a, b, out - 1, inst) || !push(b, a)))
		*inst = ft_strjoinfree("pb\n", *inst, 0, 1);
	else
		return (bf2(a, b, out, inst));
	if (is_sorted(a, b))
		return (inst);
	return (NULL);
}

int		highlgofive(t_list **a, t_list **b)
{
	int		out;
	char	*inst;

	out = 0;
	inst = ft_strnew(0);
	while (out <= 12)
	{
		if (bf(a, b, out, &inst))
		{
			ft_printf("%s", inst);
			break ;
		}
		out++;
	}
	free(inst);
	return (out <= 12 ? 1 : 0);
}
