/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:03:33 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:52:51 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	while (*(s1 + i) != '\0')
		i++;
	if ((copy = (char *)malloc(sizeof(*copy) * (i + 1))) == NULL)
		return (0);
	i = 0;
	while (*(s1 + i) != '\0')
	{
		*(copy + i) = (char)*(s1 + i);
		i++;
	}
	*(copy + i) = '\0';
	return (copy);
}
