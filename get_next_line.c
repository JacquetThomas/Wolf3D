/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:49:31 by cjacquet          #+#    #+#             */
/*   Updated: 2017/03/02 18:42:27 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_file(t_stock *stock, int fd)
{
	if (stock->tab[fd] == NULL)
		stock->tab[fd] = ft_strnew(1);
	while (!(ft_strchr(stock->tab[fd], '\n')) &&
			(stock->read_b = read(fd, stock->buff, BUFF_SIZE)) > 0)
	{
		stock->buff[stock->read_b] = '\0';
		stock->tmp = stock->tab[fd];
		stock->tab[fd] = ft_strjoin(stock->tmp, stock->buff);
		if (!stock->tab[fd])
			return (-1);
		ft_strdel(&stock->tmp);
	}
	ft_strdel(&stock->buff);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_stock	stock;

	if (fd < 0 || fd > MAX_FD || line == NULL || BUFF_SIZE <= 0 ||
	BUFF_SIZE > MAX_INT || !(stock.buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (read_file(&stock, fd) == -1 || stock.read_b == -1)
		return (-1);
	*line = ft_strsub(stock.tab[fd], 0, ft_strlenchar(stock.tab[fd], '\n'));
	if (ft_strchr(stock.tab[fd], '\n'))
	{
		stock.tmp = stock.tab[fd];
		stock.tab[fd] = ft_strdup(ft_strchr(stock.tmp, '\n') + 1);
		ft_strdel(&stock.tmp);
		return (1);
	}
	if (ft_strlenchar(stock.tab[fd], '\n') > 0)
	{
		stock.tab[fd] = stock.tab[fd] + ft_strlenchar(stock.tab[fd], '\n');
		return (1);
	}
	return (0);
}
