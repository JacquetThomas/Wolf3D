/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:53:10 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:39:51 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		burning_calc(int x, int y, t_env *env)
{
	t_calc	c;
	t_plex	deuxvinseize;

	c.point = map(x, y, env, 1);
	c.new.r = 0;
	c.new.i = 0;
	deuxvinseize.r = 0.0;
	deuxvinseize.i = 0.296;
	env->iter = 0;
	while (++env->iter < env->max_i)
	{
		c.old.r = fabs(c.new.r);
		c.old.i = fabs(c.new.i);
		if (env->fract_name == 4)
			c.new = c_add(c_mul(c.old, c.old), c.point);
		else if (env->fract_name == 5)
			c.new = c_add(c_div(c_mul(c.old, c.old),
						c_add(c.point, c.old)), deuxvinseize);
		if ((c.new.r * c.new.r + c.new.i * c.new.i) > 16)
			return (env->iter);
	}
	return (env->iter);
}

void	burning_ship(t_env *env)
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
			i = burning_calc(x, y, env);
			s = (env->grey) ? (float)i / (float)env->max_i : 1.0;
			pixel_put_image(get_color(i * 360 / env->max_i, s,
						0.8 * (i < env->max_i), env), x, y, env);
			y++;
		}
		x++;
	}
}
