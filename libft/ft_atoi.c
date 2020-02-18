/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:32:28 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 21:48:23 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nbr;

	i = 0;
	neg = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-' && (neg = -1)))
		i++;
	nbr = 0;
	while ('0' <= str[i] && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	return (neg * nbr);
}
