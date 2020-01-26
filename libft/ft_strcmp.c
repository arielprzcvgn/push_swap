/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:21:46 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/02 15:52:15 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				length;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	length = 0;
	while (*(str1 + length) == *(str2 + length))
	{
		if (*(str1 + length) == '\0' || *(str2 + length) == '\0')
			return (0);
		length++;
	}
	return (*(str1 + length) - *(str2 + length));
}
