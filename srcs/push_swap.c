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

int		main(int argc, char **argv)
{
	t_list	*pileA;
	t_list	*pileB;
    char    *instructions;

	pileA = NULL;
	pileB = NULL;
	instructions = malloc(1000); //MEMALLOC
	if (argc == 1)
		return (0);
	if (ps_init(argc, argv, &pileA) == 0 ||
		bubble(&pileA, instructions) == 0)
		return (-1);
	printf("%s\n", instructions);
	return (1);
}