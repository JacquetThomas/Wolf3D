/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 14:49:22 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		set_var(t_env *env)
{
	env->px = 0;
	env->py = 0;
	env->move = 0.1;
	env->move_r = 0;
	env->move_i = 0;
	env->max_x = 2.0;
	env->max_y = 2.0;
	env->min_x = -2.0;
	env->min_y = -2.0;
	env->julia.r = 0.285;
	env->julia.i = 0.01;
	env->c_lock = 0;
	env->color_m = 5;
	env->color_picker = 0;
	env->music = 0;
	env->help = 0;
	env->grey = 0;
	env->nvar = (env->fract_name == 3) ? 1 : 0;
	env->max_i = 200000000;//(env->fract_name == 2 || env->fract_name == 3) ? 35 : 72;
	env->auto_i = 0;
}

void		pixel_put_image(unsigned long img_color, int x, int y,
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
