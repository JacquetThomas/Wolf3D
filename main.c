/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:47:56 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 16:07:16 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(int ac, char **av)
{
	t_env	env;
	int		map[7][7] = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 2, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1},
	};

	if (ac == 1)
	{
		init_mlx(&env);
		mlx_hook(env.win, 17, (1L << 17), exit_cross, &env);
		mlx_hook(env.win, 2, 0, key_hook, &env);
		mlx_hook(env.win, 6, (1L << 6), mouse_move, &env);
		mlx_mouse_hook(env.win, mouse_hook, &env);
		mlx_loop_hook(env.mlx, draw, &env);
		mlx_loop(env.mlx);
	}
	else
		error_str(USAGE, &env, 0);
}
