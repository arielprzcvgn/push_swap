/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:37:08 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:52:00 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*copy;

	copy = (char *)s2;
	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	j = 0;
	while (*(copy + j) != '\0')
	{
		*(s1 + i + j) = *(copy + j);
		j++;
	}
	*(s1 + i + j) = '\0';
	return (s1);
}
