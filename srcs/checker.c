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

int		instruction(t_list **pilea, t_list **pileb)
{
	char	*inst;
	int		end;

	end = 0;
	inst = ft_strnew(5);
	while (get_next_line(0, &inst) == 1)
	{
		end = chooseop(inst, pilea, pileb);
		visu(pilea, pileb);
		//write(1, "\n", 1);
		if (end == 0)
			return (0);
		if (end == 2)
			return (1);
	}
	return (1);
}

int		sorted(int argc, t_list **pilea, t_list **pileb)
{
	int		i;
	t_list	*current;

	if (*pileb != NULL)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	current = *pilea;
	i = 1;
	while (argc > 2 && current->next != *pilea)
	{
		if (current->content >= current->next->content)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		current = current->next;
	}
	write(1, "OK\n", 3);
	return (1);
}

int		main(int argc, char **argv)
{
	t_list	*pilea;
	t_list	*pileb;

	pilea = NULL;
	pileb = NULL;
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &pilea) == 0 || instruction(&pilea, &pileb) == 0)
		return (-1);
	return (sorted(argc, &pilea, &pileb));
}
