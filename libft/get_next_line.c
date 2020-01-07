/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariperez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:06:01 by ariperez          #+#    #+#             */
/*   Updated: 2019/04/04 16:02:05 by ariperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

t_fd	*fd_choice(int fd, t_fd *file, char *buf)
{
	t_fd	*begin;

	begin = file;
	while ((size_t)fd != file->fd)
	{
		file = file->next;
		if (file == begin)
		{
			if (!(file = malloc(sizeof(t_fd))))
				return (NULL);
			file->buf = buf;
			file->fd = (size_t)fd;
			file->red = 0;
			file->next = begin->next;
			begin->next = file;
		}
	}
	return (file);
}

int		readline(int fd, char *buf, int *red, char **copy)
{
	int		i;
	char	end;

	end = 0;
	while (end != '\n')
	{
		if (!*buf && (*red = read(fd, buf, BUFF_SIZE)) == 0)
			return (0);
		buf[*red] = '\0';
		i = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		end = buf[i];
		buf[i] = '\0';
		*copy = ft_strjoinfree(*copy, buf, 1, 0);
		end == '\n' ? *copy = ft_strjoinfree(*copy, "\n", 1, 0) : 0;
		if (end == '\n')
			ft_memmove(buf, (buf + i + 1), *red - i);
		end == '\n' ? ft_strclr(buf + *red - i - 1) : ft_strclr(buf);
		if (end != '\n' && (*red = read(fd, buf, BUFF_SIZE)) == 0)
			return (1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*file;
	char			*copy;
	int				ret;
	char			*buf;

	ret = -1;
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (ret);
	if (!file)
	{
		if (!(file = malloc(sizeof(t_fd))))
			return (ret);
		file->buf = buf;
		file->fd = (size_t)fd;
		file->red = 0;
		file->next = file;
	}
	if (fd < 0 || !(copy = ft_strnew(1)) || read(fd, copy, 0) == -1 ||
			BUFF_SIZE < 0 || !line || !(file = fd_choice(fd, file, buf)))
		return (ret);
	ret = readline((int)file->fd, file->buf, &file->red, &copy);
	if (!(*line = ft_strdup(copy)))
		return (-1);
	free(copy);
	return (ret);
}
