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

int		instruction(t_list **a, t_list **b, t_opt *o)
{
	char	*inst;
	int		end;
	t_list	*current;

	current = *a;
	while (current && (++o->len))
		current = current->next;
	end = 0;
	inst = ft_strnew(5);
	while (get_next_line(0, &inst) == 1)
	{
		end = chooseop(inst, a, b);
		if (o->visu || o->color)
			visu(a, b, o);
		if (end == 0)
			return (0);
		if (end == 2)
			break;
	}
	free(inst);
	ft_printf("\n----------FINAL STATE----------\n");
	visu(a, b, o);
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
	t_opt	*o;

	a = NULL;
	b = NULL;
	o = NULL;
	if (argc == 1)
		return (0);
	if (!(o = malloc(sizeof(t_opt))) || ps_init(argc, argv, &a, o) == 0 ||
	instruction(&a, &b, o) == 0)
		return (-1);
	sorted(&a, &b);
	free(a);
	free(b);
	free(o);
	return (1);
}
