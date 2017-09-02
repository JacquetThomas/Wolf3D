/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:55:33 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/02 14:58:36 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

double		deg2rad(double angle)
{
	return (M_PI * (angle) / 180 );
}

double		rad2deg(double angle)
{
	return (180 * (angle) / M_PI);
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
	return (c == '0' || c == '1' || c == '2' || c == '4');
}
