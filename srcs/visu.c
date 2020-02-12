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

void	print_pile(t_list **pile, int len)
{
	t_list	*current;

	current = *pile;
	while (current && (len--))
	{
		ft_printf("% 4i", current->val);
		current = current->next;
	}
	while (len--)
		ft_printf("   ");
	ft_printf("\n");
}

void	visu(t_list **a, t_list **b, t_opt *o, char *op)
{
	if (o->visu)
	{
		ft_printf("Pile A |");
		print_pile(a, o->len);
		ft_printf("Pile B |");
		print_pile(b, o->len);
	}
	else if (o->color && !ft_strcmp(op, "pb\n"))
	{
		ft_printf("Pile A |");
		print_pile(a, o->len);
		ft_printf("Pile B |");
		print_pile(b, o->len);
	}
}
