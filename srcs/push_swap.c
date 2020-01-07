/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:46:18 by ariperez          #+#    #+#             */
/*   Updated: 2019/12/12 18:46:23 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_list **pilea)
{
	t_list	*current;

	current = *pilea;
	while (current->next != *pilea)
	{
		if (current->content >= current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

char	*get_instructions(t_list **pilea, char *instructions)
{
	bubble(pilea, instructions);
	return (instructions);
}


int		main(int argc, char **argv)
{
	t_list		*pilea;
	t_list		*pileb;
	char		*instructions;

	pilea = NULL;
	pileb = NULL;
	instructions = ft_memalloc(BUFF_SIZE);
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &pilea) == 0 ||
		get_instructions(&pilea, instructions) == 0)
		return (-1);
	printf("%s\n", instructions);
	return (1);
}
