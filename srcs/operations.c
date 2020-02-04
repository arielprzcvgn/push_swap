/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap(t_list **list)
{
	int		swap;

	swap = 0;
	if (*list && (*list)->next)
	{
		swap = (*list)->val;
		(*list)->val = (*list)->next->val;
		(*list)->next->val = swap;
		return (1);
	}
	return (1);
}

int		push(t_list **listfrom, t_list **listto)
{
	t_list		*topush;

	if (*listfrom == NULL)
		return (1);
	topush = *listfrom;
	if ((*listfrom)->next)
	{
		(*listfrom)->next->prev = (*listfrom)->prev;
		*listfrom = (*listfrom)->next;
	}
	else
		*listfrom = NULL;
	if (*listto)
	{
		topush->next = *listto;
		topush->prev = (*listto)->prev;
		(*listto)->prev = topush;
	}
	else
	{
		topush->prev = topush;
		topush->next = NULL;
	}
	*listto = topush;
	return (1);
}

int		rotate(t_list **list, int rev)
{
	if (*list && (*list)->next)
	{
		if (rev == 1)
		{
			(*list)->prev->next = *list;
			*list = (*list)->next;
			(*list)->prev->next = NULL;
		}
		if (rev == -1)
		{
			(*list)->prev->next = *list;
			*list = (*list)->prev;
			(*list)->prev->next = NULL;
		}
		return (1);
	}
	return (1);
}

int		chooseop(char *op, t_list **a, t_list **b, t_opt *o)
{
	if ((!ft_strcmp(op, "sa\n") && swap(a)) ||
	(!ft_strcmp(op, "sb\n") && swap(b)) ||
	(!ft_strcmp(op, "ss\n") && swap(a) && swap(b)) ||
	(!ft_strcmp(op, "ra\n") && rotate(a, 1)) ||
	(!ft_strcmp(op, "rb\n") && rotate(b, 1)) ||
	(!ft_strcmp(op, "rr\n") && rotate(a, 1) && rotate(b, 1)) ||
	(!ft_strcmp(op, "rra\n") && rotate(a, -1)) ||
	(!ft_strcmp(op, "rrb\n") && rotate(b, -1)) ||
	(!ft_strcmp(op, "rrr\n") && rotate(a, -1) && rotate(b, -1)) ||
	(!ft_strcmp(op, "pa\n") && push(b, a)) ||
	(!ft_strcmp(op, "pb\n") && push(a, b)))
		visu(a, b, o, op);
	else if (op[0] == '\n')
		return (2);
	else if (ft_printf("Error operation\n"))
		return (0);
	return (1);
}
