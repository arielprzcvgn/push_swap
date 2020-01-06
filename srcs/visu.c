/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:10 by ariperez          #+#    #+#             */
/*   Updated: 2019/11/19 18:00:55 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"









//UTILISER MON PRINTF !!!





int     visu(t_list **pileA, t_list **pileB)
{
    t_list  *current;

    current = *pileA;
    printf("PileA |");
    while (current && current->next != *pileA)
    {
        printf(" %i", current->content);
        current = current->next;
    }
    if (current)
        printf(" %i", current->content);
    printf("\n");
    current = *pileB;
    printf("PileB |");
    while (current && current->next != *pileB)
    {
        printf(" %i", current->content);
        current = current->next;
    }
    if (current)
        printf(" %i", current->content);
    printf("\n");
    return (1);
}