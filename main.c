/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:47:56 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/10 14:56:52 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_map(t_env *env)
{
	t_point	p;

	p.x = 0;
	while (p.x < env->max_x)
	{
		p.y = 0;
		while (p.y < env->max_y)
		{
			ft_putnbr(env->map[p.x][p.y]);
			ft_putchar(' ');
			p.y++;
		}
		p.x++;
		ft_putendl("");
	}
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 && is_wolfmap(av[1]))
	{
		env.cam.pos = search_player(av[1], &env);
		init_mlx(&env);
		draw(&env);
		printf("cam.dist : %f\n", env.cam.dist_e);
		printf("cam.little : %f\n", env.cam.little_a);
		print_map(&env);
		mlx_hook(env.win, 17, (1L << 17), exit_cross, &env);
		mlx_hook(env.win, 2, 0, key_hook, &env);
//		mlx_hook(env.win, 6, (1L << 6), mouse_move, &env);
//		mlx_mouse_hook(env.win, mouse_hook, &env);
//		mlx_loop_hook(env.mlx, draw, &env);
		mlx_loop(env.mlx);
	}
	else
		error_str(USAGE, &env, 0);
}
