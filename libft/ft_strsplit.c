/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:47:41 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:54:28 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		fill(char **splited, const char *s, int size, char c)
{
	size_t		nbwrd;
	size_t		i;

	i = size;
	nbwrd = 0;
	while (*(s + i) != '\0')
	{
		size = i;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
		if ((*(splited + nbwrd) =
					(char *)malloc(sizeof(**splited) * (i - size))) == NULL)
			return (0);
		i = size;
		while (*(s + i) != c && *(s + i) != '\0')
		{
			splited[nbwrd][i - size] = *(s + i);
			i++;
		}
		splited[nbwrd][i - size] = '\0';
		while (*(s + i) == c)
			i++;
		nbwrd++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**splited;
	size_t		nbwords;
	size_t		size;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i) == c && i < ft_strlen(s))
		i++;
	size = i;
	nbwords = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && (*(s + i + 1) == c || *(s + i + 1) == '\0'))
			nbwords++;
		i++;
	}
	if ((splited = (char **)malloc(sizeof(*splited) * (nbwords + 1))) == NULL ||
		fill(splited, s, size, c) == 0)
		return (NULL);
	splited[nbwords] = 0;
	return (splited);
}
