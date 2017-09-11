/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:16:01 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/11 19:22:27 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_up(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x + env->ray.dir.x
					* env->movespeed), (int)(env->ray.pos.y), env))
		env->ray.pos.x += env->ray.dir.x * env->movespeed;
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					+ env->ray.dir.y * env->movespeed), env))
		env->ray.pos.y += env->ray.dir.y * env->movespeed;
}

void		move_down(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x - env->ray.dir.x
					* env->movespeed), (int)(env->ray.pos.y), env))
		env->ray.pos.x -= env->ray.dir.x * env->movespeed;
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					- env->ray.dir.y * env->movespeed), env))
		env->ray.pos.y -= env->ray.dir.y * env->movespeed;
}

void		move_left(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x - env->ray.dir.y
					* env->movespeed), (int)(env->ray.pos.y), env))
		env->ray.pos.x -= env->ray.dir.y * env->movespeed;
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					+ env->ray.dir.x * env->movespeed), env))
		env->ray.pos.y += env->ray.dir.x * env->movespeed;
}

void		move_right(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x + env->ray.dir.y
					* env->movespeed), (int)(env->ray.pos.y), env))
		env->ray.pos.x += env->ray.dir.y * env->movespeed;
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					- env->ray.dir.x * env->movespeed), env))
		env->ray.pos.y -= env->ray.dir.x * env->movespeed;
}
