/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2020/02/12 20:23:11 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_pile(t_list **pile, t_opt *o, t_list *old)
{
	t_list	*current;
	int		len;

	len = o->len;
	current = *pile;
	while (current && (len--))
	{
		if (o->color && current == *pile)
			ft_printf("\033[1;33m% 4i\033[0m", current->val);
		else if (current == old)
			ft_printf("\033[1;32m% 4i\033[0m", current->val);
		else
			ft_printf("% 4i", current->val);
		current = current->next;
	}
	while (len--)
		ft_printf("   ");
	ft_printf("\n");
}

void	visu(t_list **a, t_list **b, t_opt *o, char *op)
{
	static t_list	*old_a;
	static t_list	*old_b;

	if (!old_a)
		old_a = NULL;
	if (!old_b)
		old_b = NULL;
	if (o->visu)
	{
		ft_printf("Pile A |");
		print_pile(a, o, NULL);
		ft_printf("Pile B |");
		print_pile(b, o, NULL);
		ft_printf("-------------------\n");
	}
	else if (o->color && !ft_strcmp(op, "pb\n"))
	{
		ft_printf("Pile A |");
		print_pile(a, o, old_a);
		ft_printf("Pile B |");
		print_pile(b, o, old_b);
		ft_printf("-------------------\n");
		old_a = *a ? *a : NULL;
		old_b = *b ? *b : NULL;
	}
}
