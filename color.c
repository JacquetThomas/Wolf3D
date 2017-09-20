/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 21:40:21 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			color_wall(t_env *env)
{
	if (env->side == 0)
		env->color = (env->ray.step.x == -1) ? GREEN : BLUE;
	else
		env->color = (env->ray.step.y == -1) ? ORANGE : RED;
}

unsigned int	mod_color(unsigned int color, int y, t_env *env)
{
	if (env->maze == 1)
	{
		if ((y == env->wall_h.y || y == env->wall_h.y - 1) && env->exit == 1)
			return (YELLOW);
		return (BLACK);
	}
	else
		return (color);
}

void			print_player(unsigned int color, t_env *env)
{
	t_dpoint	final;
	t_dpoint	z;

	final.x = env->ray.pos.x;
	final.y = env->ray.pos.y;
	z.x = env->ray.pos.x - floor(env->ray.pos.x);
	z.y = env->ray.pos.y - floor(env->ray.pos.y);
	if ((int)(env->ray.pos.x + 1) < env->max_x
			&& env->map[(int)(env->ray.pos.x) + 1][(int)env->ray.pos.y] == 1)
		final.x = floor(env->ray.pos.x);
	if ((int)(env->ray.pos.y + 1) < env->max_y
			&& env->map[(int)final.x][(int)(env->ray.pos.y) + 1] == 1)
		final.y = floor(env->ray.pos.y);
	if (z.x >= 0.6 && z.y >= 0.6)
	{
		if ((int)(env->ray.pos.x + 1) < env->max_x && (int)env->ray.pos.y + 1
				< env->max_y && env->map[(int)(env->ray.pos.x) +
				1][(int)env->ray.pos.y + 1] == 1)
		{
			final.x = floor(env->ray.pos.x);
			final.y = floor(env->ray.pos.y);
		}
	}
	draw_cmpss(color, final, env);
	square(color, final.y * 10, final.x * 10, env);
}

int				moving_key(int key)
{
	return (key == UP || key == DOWN || key == W || key == A || key == S
			|| key == D || key == LEFT || key == RIGHT);
}
