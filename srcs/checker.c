/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		instruction(t_list **a, t_list **b)
{
	char	*inst;
	int		end;

	end = 0;
	inst = ft_strnew(5);
	while (get_next_line(0, &inst) == 1)
	{
		end = chooseop(inst, a, b);
		//visu(a, b);
		if (end == 0)
			return (0);
		if (end == 2)
			return (1);
	}
	return (1);
}

int		sorted(t_list **a, t_list **b)
{
	int		i;
	t_list	*current;

	if (*b != NULL && ft_printf("KO\n"))
		return (0);
	current = *a;
	i = 1;
	while (current->next)
	{
		if (current->val >= current->next->val && ft_printf("KO\n"))
			return (0);
		current = current->next;
	}
	ft_printf("OK\n");
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &a) == 0 || instruction(&a, &b) == 0)
		return (-1);
	return (sorted(&a, &b));
}
