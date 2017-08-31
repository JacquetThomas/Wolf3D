/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:26:38 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/08 15:10:49 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_white(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v'\
			|| c == '\r' || c == '\n')
		return (1);
	else
		return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		n;
	char	*st;

	st = (char*)str;
	i = 0;
	n = 0;
	while (ft_is_white(*st))
		st++;
	if (*st == '-' || *st == '+')
	{
		if (*st == '-')
			n = 1;
		st++;
	}
	if (!(ft_isdigit(*st)))
		return (0);
	while (ft_isdigit(*st) && *st != '\0')
	{
		i = i * 10 + (*st - '0');
		st++;
	}
	if (n == 1)
		i = i * (-1);
	return (i);
}
