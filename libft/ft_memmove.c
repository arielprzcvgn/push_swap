/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:22:23 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:50:20 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	i = -1;
	if (d < s)
	{
		while (++i < len)
			*(d + i) = *(s + i);
	}
	else if (s < d)
	{
		while (++i < len)
			*(d + len - i - 1) = *(s + len - i - 1);
	}
	return (dst);
}
