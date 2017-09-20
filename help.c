/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:46:58 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 21:37:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_help(t_env *env)
{
	int	d;
	int	h;

	d = 202;
	h = W_HEIGHT + 200;
	mlx_string_put(env->mlx, env->win, d, h - 200, RED,
			"All these commands are available");
	mlx_string_put(env->mlx, env->win, d, h - 180, WHITE,
			"Music: (m) ON/OFF");
	mlx_string_put(env->mlx, env->win, d, h - 160, WHITE,
			"Rotate Camera: (<) left/ (>) right");
	mlx_string_put(env->mlx, env->win, d, h - 140, WHITE,
			"Move: (a)left (d)right (w)up (s)down");
	mlx_string_put(env->mlx, env->win, d, h - 120, WHITE,
			"Run: (shift)");
	mlx_string_put(env->mlx, env->win, d, h - 100, WHITE,
			"Change mode: (1) Maze / (2) Vanilla");
	mlx_string_put(env->mlx, env->win, d, h - 80, WHITE,
			"Quit: (esc)");
	mlx_string_put(env->mlx, env->win, d, h - 60, WHITE,
			"Help menu: (h) open/close");
}

void	print_help2(int d, int h, t_env *env)
{
	mlx_string_put(env->mlx, env->win, d, h - 80, WHITE,
			"Color mode: (g) Grey pastel / Rainbow");
	mlx_string_put(env->mlx, env->win, d, h - 60, WHITE,
			"Mouse: zoom in&out w/ wheel or button");
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

int		check_map(t_env *env)
{
	int		x;
	int		y;
	int		player;

	player = 0;
	x = 0;
	if (env->max_x > 20 || env->max_y > 20)
		error_str("Wrong map_file, map too large, max 20*20", env, 1);
	while (x < env->max_x)
	{
		y = 0;
		while (y < env->max_y)
		{
			if ((x == 0 || y == 0 || x == env->max_x - 1
						|| y == env->max_y - 1) && env->map[x][y] != 1)
				return (0);
			if (env->map[x][y] == 2)
				player += 1;
			y++;
		}
		x++;
	}
	if (player != 1)
		error_str("Wrong map_file, no or too much player(s) set", env, 1);
	return (player);
}
