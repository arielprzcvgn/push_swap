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
	if (*list)
	{
		if ((*list)->next == *list || *list == NULL)
			return (0);
		swap = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = swap;
		return (1);
	}
	return (0);
}

int		swapp(t_list **list)
{
	t_list		*swap;

	if (*list && (*list)->next != *list)
	{
		swap = *list;
		*list = (*list)->next;

		(*list)->prev = swap->prev;
		(*list)->prev->next = *list;
		swap->next = (*list)->next;
		swap->next->prev = swap;
		(*list)->next = swap;
		swap->prev = *list;
		return (1);
	}
	return (0);
}

int		push(t_list **listfrom, t_list **listto)
{
	t_list		*topush;

	if (*listfrom == NULL)
		return (0);
	topush = *listfrom;
	(*listfrom)->prev->next = (*listfrom)->next;
	(*listfrom)->next->prev = (*listfrom)->prev;
	*listfrom = (*listfrom == (*listfrom)->next) ? NULL : (*listfrom)->next;
	if (*listto)
	{
		topush->next = *listto;
		topush->prev = (*listto)->prev;
		(*listto)->prev->next = topush;
		(*listto)->prev = topush;
	}
	else
	{
		topush->next = topush;
		topush->prev = topush;
	}
	*listto = topush;
	return (1);
}

int		rotate(t_list **list, int rev)
{
	if (*list)
	{
		if ((*list)->next == *list || *list == NULL)
			return (0);
		if (rev == 0)
			*list = (*list)->next;
		if (rev == 1)
			*list = (*list)->prev;
		return (1);
	}
	return (0);
}

int		notanop(char *op)
{
	if (op[0] == '\n')
		return (2);
	write(1, "Error operation\n", 7);
	return (0);
}

int		chooseop(char *op, t_list **pilea, t_list **pileb)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap(pilea);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(pileb);
	else if (ft_strcmp(op, "ss\n") == 0 && (swap(pilea) || 1))
		swap(pileb);
	else if (ft_strcmp(op, "pa\n") == 0)
		push(pileb, pilea);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(pilea, pileb);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate(pilea, 0);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(pileb, 0);
	else if (ft_strcmp(op, "rr\n") == 0 && (rotate(pilea, 0) || 1))
		rotate(pileb, 0);
	else if (ft_strcmp(op, "rra\n") == 0)
		rotate(pilea, 1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rotate(pileb, 1);
	else if (ft_strcmp(op, "rrr\n") == 0 && (rotate(pilea, 1) || 1))
		rotate(pileb, 1);
	else
		return (notanop(op));
	return (1);
}
