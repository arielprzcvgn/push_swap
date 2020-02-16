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

char	**copy_tab(char **tab, char **argv, int argc, int i)
{
	int		j;

	j = 0;
	if ((tab = malloc(sizeof(*tab) * (argc - i + 1))) == NULL)
		return (NULL);
	while (i + j < argc)
	{
		if ((tab[j] = ft_strdup(argv[i + j])) == NULL)
			return (NULL);	
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

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
	system("leaks checker");
	return (error == 0 ? 1 : 0);
}
