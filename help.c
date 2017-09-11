/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:46:58 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/11 17:45:00 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_help(t_env *env)
{
	int	d;
	int	h;

	d = 202;
	h = W_HEIGHT + 200;
//	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 200);
//	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 100);
//	mlx_put_image_to_window(env->mlx, env->win, env->img_b, -120, h - 220);
	mlx_string_put(env->mlx, env->win, d, h - 200, RED,
			"All these commands are available");
	mlx_string_put(env->mlx, env->win, d, h - 120, WHITE,
			"Music: (m) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 100, WHITE,
			"Psyche mode: (p) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 80, WHITE,
			"Rotate Camera: (<) left/ (>) right");
	mlx_string_put(env->mlx, env->win, d, h - 60, WHITE,
			"Move: (a)left (d)right (w)up (s)down");
	mlx_string_put(env->mlx, env->win, d, h - 40, WHITE,
			"Speed: numpad (-) decrease / (+) increase");
	mlx_string_put(env->mlx, env->win, d, h - 20, WHITE,
			"Change mode: (1) Maze / (2) Vanilla");
	//print_help2(d, h, env);
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
