/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/01 15:09:14 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	line(t_point b, t_point c, t_env *env)
{
	int				a[6];

	//env->color = set_color(env->map[env->i][env->j], env->black, env);
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

void	set_var(t_env *env)
{
	env->cam.angle = 60.0;
	env->cam.little_a = env->cam.angle / (double)W_WIDTH;
	printf("%f\n", env->cam.little_a);
	env->cam.dist_e = (double)(W_WIDTH / 2) / tan(deg2rad(env->cam.angle / 2));
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
