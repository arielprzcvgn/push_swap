/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:07:07 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:50:27 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = b;
	i = 0;
	while (i < len)
	{
		*(p + i) = c;
		i++;
	}
	return (b);
}
