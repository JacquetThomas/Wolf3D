/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:39:59 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:40:56 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		julia_calc(int x, int y, t_env *env)
{
	t_calc	c;

	c.point = map(x, y, env, 1);
	c.new.r = c.point.r;
	c.new.i = c.point.i;
	env->iter = 0;
	while (++env->iter < env->max_i)
	{
		c.old.r = c.new.r;
		c.old.i = c.new.i;
		c.new.r = c.old.r * c.old.r - c.old.i * c.old.i + env->julia.r;
		c.new.i = 2 * c.old.r * c.old.i + env->julia.i;
		if ((c.new.r * c.new.r + c.new.i * c.new.i) > 16)
			return (env->iter);
	}
	return (env->iter);
}

void	julia(t_env *env)
{
	int		y;
	int		x;
	int		i;
	float	s;

	x = 1;
	while (x < W_WIDTH)
	{
		y = 1;
		while (y < W_HEIGHT)
		{
			i = julia_calc(x, y, env);
			s = env->grey ? (float)i / (float)env->max_i : 1.0;
			pixel_put_image(get_color(i * 360 / env->max_i, s,
						0.8 * (i < env->max_i), env),
					x, y, env);
			y++;
		}
		x++;
	}
}
