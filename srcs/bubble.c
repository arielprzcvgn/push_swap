/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		sort(t_list **pileA)
{
	int		i;
	t_list	*current;

	current = *pileA;
	i = 1;
	while(current->next != *pileA)
	{
		if (current->content >= current->next->content)
			return (0);
		current = current->next;
	}
	return(1);
}

char    *bubble(t_list **pileA, char *instructions)
{
    t_list  *current;
    int     swap;

    current = *pileA;
    while (sort(pileA) != 1)
    {
        if (current->content > current->next->content)
        {
            swap = current->content;
            current->content = current->next->content;
            current->next->content = swap;
            printf("lol\n");
            ft_strcat(instructions, "sa\n"); //SEGFAULT
        }
        ft_strcat(instructions, "ra\n");
    }
    return (instructions);
}