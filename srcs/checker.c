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
#include <stdio.h>

int		instruction(t_list **pileA, t_list **pileB)
{
	char	buf[BUFF_SIZE];
	int		red;
	int		end;

	red = 0;
	end = 0;
	while ((red = read(0, buf, BUFF_SIZE)) > 0)
	{
		end = chooseop(buf, pileA, pileB);
		visu(pileA, pileB);
		if (end == 0)
			return (0);
		if (end == 2)
			return (1);
		ft_strclr(buf);
	}
	return (1);
}

int		sorted(int argc, t_list **pileA, t_list **pileB)
{
	int		i;
	t_list	*current;

	if (*pileB != NULL)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	current = *pileA;
	i = 1;
	while(argc > 2 && current->next != *pileA)
	{
		if (current->content >= current->next->content)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		current = current->next;
	}
	write(1, "OK\n", 3);
	return(1);
}

int		main(int argc, char **argv)
{
	t_list	*pileA;
	t_list	*pileB;

	pileA = NULL;
	pileB = NULL;
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &pileA) == 0 || instruction(&pileA, &pileB) == 0)
		return (-1);
	return (sorted(argc, &pileA, &pileB));
}
