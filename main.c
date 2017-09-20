/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:47:56 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 21:51:13 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		analyze(char *str, t_env *env)
{
	if (ft_strstr(str, "maze") != NULL)
	{
		env->maze = 1;
		return (1);
	}
	else if (ft_strstr(str, "vanilla") != NULL)
	{
		env->maze = 0;
		return (1);
	}
	ft_putendl("Choose your mode [vanilla | maze]");
	return (0);
}

void	ask_mode(t_env *env)
{
	int		ret;
	char	*ans;
	int		flag;

	flag = 0;
	ft_putendl("Choose your mode [vanilla | maze]");
	while ((ret = get_next_line(0, &ans)) >= 0 && flag == 0)
	{
		flag = analyze(ans, env);
		if (flag == 1)
		{
			free(ans);
			if (env->maze)
			{
				ft_putendl("You got 3min to get out of this maze, good luck.");
				countdown();
				env->start = time(NULL);
			}
			return ;
		}
	}
	free(ans);
}

int		main(int ac, char **av)
{
	t_env	env;
	char	*map;

	(void)av;
	map = "Ressources/map.wolf";
	if (ac == 1)
	{
		env.cam.pos = search_player(map, &env);
		ask_mode(&env);
		init_mlx(&env);
		draw(&env);
		mlx_hook(env.win, 17, (1L << 17), exit_cross, &env);
		mlx_hook(env.win, 2, 0, key_hook, &env);
		mlx_loop_hook(env.mlx, draw, &env);
		mlx_loop(env.mlx);
	}
	else
		error_str(USAGE, &env, 0);
}
