/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:31:30 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:40:42 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_mlx(t_env *env)
{
	set_var(env);
	if (!(env->mlx = mlx_init()))
		error_init(env, 1);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT + 100,
					"Fract'ol")))
		error_init(env, 2);
	if (!(env->img = mlx_new_image(env->mlx, W_WIDTH, W_HEIGHT)))
		error_init(env, 2);
	if (!(env->img_b = mlx_new_image(env->mlx, W_WIDTH, 100)))
		error_init(env, 2);
	if (!(env->data = mlx_get_data_addr(env->img, &env->bpp,
					&env->sizeline, &env->endian)))
		error_init(env, 2);
	if (!(env->data_b = mlx_get_data_addr(env->img_b, &env->bpp,
					&env->sizeline_b, &env->endian)))
		error_init(env, 2);
	make_it_b(env);
	if (env->music)
		system("afplay wait.mp3 &");
}

char	*fract_name(t_env *env)
{
	if (env->fract_name == 0)
		return ("Mandelbrot");
	if (env->fract_name == 1)
		return ("Julia");
	if (env->fract_name == 2)
		return ("Newton");
	if (env->fract_name == 3)
		return ("Variation of Newton");
	if (env->fract_name == 4)
		return ("Burning ship");
	if (env->fract_name == 5)
		return ("Beach");
	if (env->fract_name == 6)
		return ("Melting-pot");
	if (env->fract_name == 7)
		return ("Tricorn");
	return ("wolf");
}

void	pixel_b(unsigned int img_color, int x, int y, t_env *env)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	(void)img_color;
	if (x > 0 && y > 0 && x < W_WIDTH && y < 100)
	{
		r = ((img_color & 0xFF0000) >> 16);
		g = ((img_color & 0xFF00) >> 8);
		b = (img_color & 0xFF);
		env->data_b[(y * env->sizeline_b) + ((env->bpp / 8) * x)] = b;
		env->data_b[(y * env->sizeline_b) + ((env->bpp / 8) * x) + 1] = g;
		env->data_b[(y * env->sizeline_b) + ((env->bpp / 8) * x) + 2] = r;
	}
}

void	make_it_uni(t_env *env, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_WIDTH)
	{
		j = 0;
		while (j < W_HEIGHT - 100)
		{
			pixel_put_image(color, i, j, env);
			j++;
		}
		i++;
	}
}

void	make_it_b(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_WIDTH)
	{
		j = 0;
		while (j < 100)
		{
			pixel_b(BLACK, i, j, env);
			j++;
		}
		i++;
	}
}
