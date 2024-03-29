/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:55:33 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 15:59:48 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			test_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!is_white(str[i]) && str[i] != '-' && !is_num(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int			is_num(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == '5');
}

double		deg2rad(double angle)
{
	return (M_PI * (angle) / 180);
}

t_point		init_point(int x, int y)
{
	t_point	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_dpoint	init_dpoint(double x, double y)
{
	t_dpoint	new;

	new.x = x;
	new.y = y;
	return (new);
}
