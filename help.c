/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:46:58 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:39:26 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_help(t_env *env)
{
	int	d;
	int	h;

	d = 2;
	h = W_HEIGHT + 100;
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 200);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 100);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 220);
	mlx_string_put(env->mlx, env->win, d, h - 220, RED,
			"All these commands are available");
	mlx_string_put(env->mlx, env->win, d, h - 200, WHITE,
			"Music: (m) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 180, WHITE,
			"Psyche mode: (p) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 160, WHITE,
			"Center zoom: (+) In / (-) Out");
	mlx_string_put(env->mlx, env->win, d, h - 140, WHITE,
			"Move: arrow keys (<)left (>)right (^)up (v)down");
	mlx_string_put(env->mlx, env->win, d, h - 120, WHITE,
			"Lock Julia const.: (l)ock");
	mlx_string_put(env->mlx, env->win, d, h - 100, WHITE,
			"Change fractals: (1-8)");
	print_help2(d, h, env);
}

void	print_help2(int d, int h, t_env *env)
{
	mlx_string_put(env->mlx, env->win, d, h - 80, WHITE,
			"Color mode: (g) Grey pastel / Rainbow");
	mlx_string_put(env->mlx, env->win, d, h - 60, WHITE,
			"Mouse: zoom in&out w/ wheel or button");
	mlx_string_put(env->mlx, env->win, d, h - 40, WHITE,
			"Quit: (esc) or (q)    | Reset: (z)");
	mlx_string_put(env->mlx, env->win, d, h - 20, WHITE,
			"Help menu: (h) open/close");
}

void	create_help(t_env *env)
{
	print_help(env);
	env->help = 1;
}

void	destroy_help(t_env *env)
{
	env->help = 0;
}
