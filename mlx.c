/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/04 17:13:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	line(t_point b, t_point c, t_env *env)
{
	int				a[6];

	a[0] = abs(c.x - b.x);
	a[1] = abs(c.y - b.y);
	a[4] = b.x < c.x ? 1 : -1;
	a[5] = b.y < c.y ? 1 : -1;
	a[2] = (a[0] > a[1] ? a[0] : -a[1]) / 2;
	while (1)
	{
		pixel_put_image(env->color, b.x, b.y, env);
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

void	square(unsigned int color, int x, int y, t_env *env)
{
	int	i;
	int	j;

	(void)env;
//	printf("x : %d // y : %d\n", x, y);
//	if (color == RED && x / 10 <= env->max_x && y / 10 <= env->max_y
//			&& env->map[(int)(x / 10) + 1][(int)(y/10) + 1] == 1)
//	{
//		y = y - 10;
//		x = x - 10;
//	}
	i = y;
	while (i < y + 10)
	{
		j = x;
		while (j < x + 10)
		{
			pixel_b(color, j, i, env);
			j++;
		}
		i++;
	}
}

void	put_line(int x, t_env *env)
{
	int				y;
	unsigned int	color;

	y = 0;
	while (y < W_HEIGHT)
	{
		if (y >= 0 && y < env->wall_h.x)
			color = BLACK;
		else if (y >= env->wall_h.x && y <= env->wall_h.y)
			color = env->color;
		else
			color = BROWN;
		pixel_put_image(color, x, y, env);
		y++;
	}
}

void	set_var(t_env *env)
{
	env->cmpss.r = 12;
	env->rotspeed = 0.1;
	env->movespeed = 0.2;
	env->ray.dir.x = -1;
	env->ray.dir.y = 0;
	env->ray.plane.x = 0;
	env->ray.plane.y = 0.66;
	env->ray.pos.x = env->cam.pos.x;
	env->ray.pos.y = env->cam.pos.y;
	env->music = 0;
}

void	pixel_put_image(unsigned long img_color, int x, int y,
		t_env *env)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (x > 0 && y > 0 && x < W_WIDTH && y < W_HEIGHT)
	{
		r = ((img_color & 0xFF0000) >> 16);
		g = ((img_color & 0xFF00) >> 8);
		b = (img_color & 0xFF);
		env->data[(y * env->sizeline) + ((env->bpp / 8) * x)] = b;
		env->data[(y * env->sizeline) + ((env->bpp / 8) * x) + 1] = g;
		env->data[(y * env->sizeline) + ((env->bpp / 8) * x) + 2] = r;
	}
}
