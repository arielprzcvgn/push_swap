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
	return (0);
}

int		push(t_list **listfrom, t_list **listto)
{
	t_list		*topush;

	if (*listfrom == NULL)
		return (0);
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
	return (0);
}

int		notanop(char *op)
{
	if (op[0] == '\n')
		return (2);
	ft_printf("Error operation\n");
	return (0);
}

/*int		chooseop(char *op, t_list **a, t_list **b)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap(b);
	else if (ft_strcmp(op, "ss\n") == 0 && (swap(a) || 1))
		swap(b);
	else if (ft_strcmp(op, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate(a, 1);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate(b, 1);
	else if (ft_strcmp(op, "rr\n") == 0 && (rotate(a, 1) || 1))
		rotate(b, 1);
	else if (ft_strcmp(op, "rra\n") == 0)
		rotate(a, -1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		rotate(b, -1);
	else if (ft_strcmp(op, "rrr\n") == 0 && (rotate(a, -1) || 1))
		rotate(b, -1);
	else
		return (notanop(op));
	return (1);
}

int		notanop(char *op)
{
	
	
	return (0);
}
*/
int		chooseop(char *op, t_list **a, t_list **b)
{
	if (((!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n")) && swap(a)) ||
	((!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n")) && swap(b)))
		;
	else if (ft_strcmp(op, "pa\n") == 0)
		push(b, a);
	else if (ft_strcmp(op, "pb\n") == 0)
		push(a, b);
	else if (ft_strcmp(op, "ra\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotate(a, 1);
	else if (ft_strcmp(op, "rb\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotate(b, 1);
	else if (ft_strcmp(op, "rra\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		rotate(a, -1);
	else if (ft_strcmp(op, "rrb\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		rotate(b, -1);
	else if (op[0] == '\n')
		return (2);
	else
		ft_printf("Error operation\n");
	return (1);
}
