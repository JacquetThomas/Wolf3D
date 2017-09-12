/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:55:42 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 20:10:53 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		draw(t_env *env)
{
	call_raycast(env);
	if (!env->maze)
		call_minimap(env);
	print_player(RED, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, 0, W_HEIGHT);
	print_info(env);
	if (env->help == 1)
		print_help(env);
	return (1);
}

void	print_info(t_env *env)
{
	char	*ito;
	time_t	diff;

	mlx_string_put(env->mlx, env->win, W_WIDTH - 85, 0, WHITE, "(h)elp ?");
	mlx_string_put(env->mlx, env->win, 2, 0, WHITE, "Music:");
	if (env->music)
		mlx_string_put(env->mlx, env->win, 67, 0, WHITE, "ON");
	else
		mlx_string_put(env->mlx, env->win, 67, 0, WHITE, "OFF");
	if (env->maze)
	{
		checking_time(env);
		diff = M_TIME - (env->now - env->start);
		ito = ft_itoa(diff);
		mlx_string_put(env->mlx, env->win, W_WIDTH / 3, 0, RED,
				"Remaining time: ");
		mlx_string_put(env->mlx, env->win, W_WIDTH / 3 + 150, 0, RED, ito);
		free(ito);
	}
}
