/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:38:39 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:41:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mandelbrot_calc(int x, int y, t_env *env)
{
	t_calc	c;

	c.point = map(x, y, env, 1);
	c.new.r = 0;
	c.new.i = 0;
	env->iter = 0;
	while (++env->iter < env->max_i)
	{
		c.old = c.new;
		c.old.i = (env->fract_name == 7) ? -c.new.i : c.new.i;
		c.new = c_add(c_mul(c.old, c.old), c.point);
		if ((c.new.r * c.new.r + c.new.i * c.new.i) > 16)
			return (env->iter);
	}
	return (env->iter);
}

void	mandelbrot(t_env *env)
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
			i = mandelbrot_calc(x, y, env);
			s = env->grey ? (float)i / (float)env->max_i : 1.0;
			pixel_put_image(get_color(i * 360 / env->max_i, s,
						0.8 * (i < env->max_i), env), x, y, env);
			y++;
		}
		x++;
	}
}

int		melting_calc(int x, int y, t_env *env)
{
	t_calc	c;

	c.point = map(x, y, env, 1);
	c.new.r = 0;
	c.new.i = 0;
	env->iter = 0;
	while (++env->iter < env->max_i)
	{
		if (env->iter % 2 == 1)
		{
			c.old = c.new;
			c.new = c_add(c_mul(c.old, c.old), c.point);
		}
		else
		{
			c.old.r = fabs(c.new.r);
			c.old.i = fabs(c.new.i);
			c.new = c_add(c_mul(c.old, c.old), c.point);
		}
		if ((c.new.r * c.new.r + c.new.i * c.new.i) > 16)
			return (env->iter);
	}
	return (env->iter);
}

void	melting_pot(t_env *env)
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
			i = melting_calc(x, y, env);
			s = env->grey ? (float)i / (float)env->max_i : 1.0;
			pixel_put_image(get_color(i * 360 / env->max_i, s,
						0.8 * (i < env->max_i), env), x, y, env);
			y++;
		}
		x++;
	}
}
