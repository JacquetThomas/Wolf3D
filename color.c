/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/10 15:49:23 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color_wall(t_env *env)
{
	if (env->side == 0)
		env->color = (env->ray.step.x == -1) ? GREEN : BLUE;
	else
		env->color = (env->ray.step.y == -1) ? ORANGE : RED;
}

void		print_player(unsigned int color, t_env *env)
{
	t_dpoint	final;

	final.x = env->ray.pos.x;
	final.y = env->ray.pos.y;
	if ((int)(env->ray.pos.x + 1) < env->max_x
			&& env->map[(int)env->ray.pos.x + 1][(int)env->ray.pos.y] == 1)
		final.x = env->ray.pos.x - (env->ray.pos.x - (int)env->ray.pos.x);
	if ((int)(env->ray.pos.y + 1) < env->max_y
			&& env->map[(int)final.x][(int)env->ray.pos.y + 1] == 1)
		final.y = env->ray.pos.y - (env->ray.pos.y - (int)env->ray.pos.y);
	draw_cmpss(color, final, env);
	square(color, final.y * 10, final.x * 10, env);
}

int			moving_key(int key)
{
	return (key == UP || key == DOWN || key == W || key == A || key == S
			|| key == D || key == LEFT || key == RIGHT);
}
