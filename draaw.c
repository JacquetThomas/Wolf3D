/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 11:55:42 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/04 17:10:13 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		draw(t_env *env)
{
	call_raycast(env);
	call_minimap(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->img_b, 0, W_HEIGHT);
	print_info(env);
//	if (env->help == 1)
//		print_help(env);
	return (1);
}

void	print_info(t_env *env)
{
//	char *ito;

	mlx_string_put(env->mlx, env->win, W_WIDTH - 85, 0, 0x00FF0000, "(h)elp ?");
//	if (env->fract_name == 1)
//	{
//		ito = (env->c_lock) ? "Yes" : "No";
//		mlx_string_put(env->mlx, env->win, 2, 60, 0x00FF0000,
//				"Const. lock:");
//		mlx_string_put(env->mlx, env->win, 122, 60, 0x00FF0000, ito);
//		ito = (env->move_r) ? "Yes" : "No";
//		mlx_string_put(env->mlx, env->win, 2, 80, 0x00FF0000,
//				"move XY :");
//		mlx_string_put(env->mlx, env->win, 102, 80, 0x00FF0000, ito);
//		ito = (env->move_i) ? "Yes" : "No";
//		mlx_string_put(env->mlx, env->win, 132, 80, 0x00FF0000, ito);
//	}
//	mlx_string_put(env->mlx, env->win, 2, 20, 0x00FF0000, "Psyche:");
//	ito = (env->color_picker) ? "Oh Yeah man" : "Nop";
//	mlx_string_put(env->mlx, env->win, 75, 20, 0x00FF0000, ito);
//	mlx_string_put(env->mlx, env->win, W_WIDTH / 3, 0, 0x00FFFFFF,
//			fract_name(env));
//	ito = ft_itoa(env->max_i);
//	mlx_string_put(env->mlx, env->win, 120, 40, 0x00FF0000, ito);
//	free(ito);
//	print_info2(env);
}

/*void	print_info2(t_env *env)
{
	char	*ito;

	mlx_string_put(env->mlx, env->win, 2, 40, 0x00FF0000, "Iterations:");
	ito = (env->auto_i) ? "auto" : "manual";
	mlx_string_put(env->mlx, env->win, 160, 40, 0x00FF0000, ito);
	mlx_string_put(env->mlx, env->win, 2, 0, 0x00FF0000, "Music:");
	if (env->music)
		mlx_string_put(env->mlx, env->win, 67, 0, 0x00FF0000, "ON");
	else
		mlx_string_put(env->mlx, env->win, 67, 0, 0x00FF0000, "OFF");
}*/
