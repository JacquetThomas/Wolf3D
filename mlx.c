/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/03 13:49:43 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	line(t_point b, t_point c, t_env *env)
{
	int				a[6];

//	env->color = GREEN;//set_color(env->map[env->i][env->j], env->black, env);
	a[0] = abs(c.x - b.x);
	a[1] = abs(c.y - b.y);
	a[4] = b.x < c.x ? 1 : -1;
	a[5] = b.y < c.y ? 1 : -1;
	a[2] = (a[0] > a[1] ? a[0] : -a[1]) / 2;
	while (1)
	{
		pixel_b(env->color, b.x, b.y, env);
	//	pixel_put_image(env->color, b.x, b.y, env);
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

	i = y;
	(void)env;
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
	t_point	b;
	t_point	c;

	b.x = x;
	c.x = x;
	b.y = env->wall_h.x;
	c.y = env->wall_h.y;
		line(b, c, env);
	// basically it's gonna call line for the top to the begin of the wall
	// and for begin wall to begin floor and finally for begin floor to
	// bottom of the window
	// line take a point b and a point c that stand for x,y of begin
	// and x,y of end of the line to draw
	// abracadabra
}

void	set_var(t_env *env)
{
	env->cam.speed = 0.2;
	env->cam.angle = 0;
	env->cam.rotspeed = 0.2;
	env->cmpss.pos.x = 150;
	env->cmpss.pos.y = 50;
	env->cmpss.r = 20;
//	env->cam.dir = init_point(0, 1);
//	env->cam.plane = init_dpoint(0.0, 0.6);
//	env->cam.angle = 60.0;
//	env->cam.little_a = env->cam.angle / (double)W_WIDTH;
//	env->cam.dist_e = (double)(W_WIDTH / 2) / tan(deg2rad(env->cam.angle / 2));
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
