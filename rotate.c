/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 17:22:57 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 17:47:12 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define RAY env->ray

static void	rotate_right(t_dpoint olddir, t_dpoint oldplane, t_env *env)
{
	RAY.dir.x = RAY.dir.x * cos(-env->rotspeed)
		- RAY.dir.y * sin(-env->rotspeed);
	RAY.dir.y = olddir.x * sin(-env->rotspeed)
		+ RAY.dir.y * cos(-env->rotspeed);
	RAY.plane.x = RAY.plane.x * cos(-env->rotspeed)
		- RAY.plane.y * sin(-env->rotspeed);
	RAY.plane.y = oldplane.x * sin(-env->rotspeed)
		+ RAY.plane.y * cos(-env->rotspeed);
}

static void	rotate_left(t_dpoint olddir, t_dpoint oldplane, t_env *env)
{
	RAY.dir.x = RAY.dir.x * cos(env->rotspeed)
		- RAY.dir.y * sin(env->rotspeed);
	RAY.dir.y = olddir.x * sin(env->rotspeed)
		+ RAY.dir.y * cos(env->rotspeed);
	RAY.plane.x = RAY.plane.x * cos(env->rotspeed)
		- RAY.plane.y * sin(env->rotspeed);
	RAY.plane.y = oldplane.x * sin(env->rotspeed)
		+ RAY.plane.y * cos(env->rotspeed);
}

void		rotate(int keycode, t_env *env)
{
	t_dpoint		olddir;
	t_dpoint		oldplane;

	oldplane = RAY.plane;
	olddir = RAY.dir;
	if (keycode == RIGHT)
		rotate_right(olddir, oldplane, env);
	if (keycode == LEFT)
		rotate_left(olddir, oldplane, env);
}
