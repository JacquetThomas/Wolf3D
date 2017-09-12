/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:16:01 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 19:32:16 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_up(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x + env->ray.dir.x
					* (env->movespeed * env->run)), (int)(env->ray.pos.y), env))
		env->ray.pos.x += env->ray.dir.x * (env->movespeed * env->run);
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					+ env->ray.dir.y * (env->movespeed * env->run)), env))
		env->ray.pos.y += env->ray.dir.y * (env->movespeed * env->run);
}

void		move_down(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x - env->ray.dir.x
					* (env->movespeed * env->run)), (int)(env->ray.pos.y), env))
		env->ray.pos.x -= env->ray.dir.x * (env->movespeed * env->run);
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					- env->ray.dir.y * (env->movespeed * env->run)), env))
		env->ray.pos.y -= env->ray.dir.y * (env->movespeed * env->run);
}

void		move_left(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x - env->ray.dir.y
					* (env->movespeed * env->run)), (int)(env->ray.pos.y), env))
		env->ray.pos.x -= env->ray.dir.y * (env->movespeed * env->run);
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					+ env->ray.dir.x * (env->movespeed * env->run)), env))
		env->ray.pos.y += env->ray.dir.x * (env->movespeed * env->run);
}

void		move_right(t_env *env)
{
	if (check_grid((int)(env->ray.pos.x + env->ray.dir.y
					* (env->movespeed * env->run)), (int)(env->ray.pos.y), env))
		env->ray.pos.x += env->ray.dir.y * (env->movespeed * env->run);
	if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					- env->ray.dir.x * (env->movespeed * env->run)), env))
		env->ray.pos.y -= env->ray.dir.x * (env->movespeed * env->run);
}
