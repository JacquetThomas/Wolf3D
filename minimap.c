/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 10:53:01 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/09 15:42:58 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		call_minimap(t_env *env)
{
	t_point	it;

	it.x = 0;
	while (it.x < env->max_x)
	{
		it.y = 0;
		while (it.y < env->max_y)
		{
			if (env->map[it.x][it.y] == 1)
			{
				square(YELLOW, it.x * 10, it.y * 10, env);
				env->color = BLACK;
			}
			else if (env->map[it.x][it.y] == 2)
			{
				env->color = RED;
				square(RED, env->ray.pos.x * 10, env->ray.pos.y * 10, env);
			}
			it.y++;
		}
		it.x++;
	}
	draw_cmpss(RED, env);
}

static void	line_b(t_point b, t_point c, t_env *env)
{
	int				a[6];

	a[0] = abs(c.x - b.x);
	a[1] = abs(c.y - b.y);
	a[4] = b.x < c.x ? 1 : -1;
	a[5] = b.y < c.y ? 1 : -1;
	a[2] = (a[0] > a[1] ? a[0] : -a[1]) / 2;
	while (1)
	{
		pixel_b(env->color, b.x, b.y, env);
		if (b.x == c.x && b.y == c.y)
			break ;
		a[3] = a[2];
		if (a[3] > -a[0])
		{
			a[2] -= a[1];
			b.x += a[4];
		}
		if (a[3] < a[1])
		{
			a[2] += a[0];
			b.y += a[5];
		}
	}
}

void		draw_cmpss(unsigned int color, t_env *env)
{
	t_point	end;
	t_point	rel;
	double	angle;

	angle = (atan2((env->ray.plane.y - env->ray.dir.y),
				(env->ray.plane.x - env->ray.dir.x)) + M_PI) * 180 / M_PI;
	printf("angle : %f\n", angle);
	env->color = color;
	rel.x = env->ray.pos.x * 10 + 5;
	rel.y = env->ray.pos.y * 10 + 5;
	end.x = rel.x + cos(deg2rad(angle - 38)) * env->cmpss.r;
	end.y = rel.y + sin(deg2rad(angle - 38)) * env->cmpss.r;
	line_b(rel, end, env);
}
