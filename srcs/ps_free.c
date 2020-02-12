/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

int		free_list(t_list **list)
{
	t_list	*current;

	current = *list;
	while (current->next)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
	return (1);
}

int		free_deb_hug(t_list **a, t_list **b, t_opt *o, int error)
{
	if (error)
		write(2, "Error\n", 6);
	if (error && o && o->debug &&
	((error == 2 && write(2, "Invalid argument or duplicate\n", 30)) ||
	(error == 3 && write(2, "Invalid operation\n", 18))))
		;
	if (a && *a)
		free_list(a);
	if (b && *b)
		free_list(b);
	if (o)
		free(o);
	while (1)
		;
	return (!error ? 1 : 0);
}
