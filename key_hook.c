/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/11 19:14:44 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *env)
{
	checking_time(env);
	key_hook2(keycode, env);
	return (1);
}

int		key_hook2(int keycode, t_env *env)
{
	key_hook3(keycode, env);
	return (1);
}

int		key_hook3(int keycode, t_env *env)
{
	key_hook4(keycode, env);
	return (1);
}

int		key_hook4(int keycode, t_env *env)
{
	if (keycode == 4)
	{
		if (env->help)
			destroy_help(env);
		else
			create_help(env);
	}
	key_hook5(keycode, env);
	return (1);
}

int		key_hook5(int keycode, t_env *env)
{
	t_dpoint		olddir;
	t_dpoint		oldplane;

	oldplane = env->ray.plane;
	olddir = env->ray.dir;
	if (moving_key(keycode))
	{
		print_player(BLACK, env);
		env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 0;
		if (keycode == D)
		{
			if (check_grid((int)(env->ray.pos.x + env->ray.dir.y
						* env->movespeed), (int)(env->ray.pos.y), env))
			env->ray.pos.x += env->ray.dir.y * env->movespeed;
			if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
						- env->ray.dir.x * env->movespeed), env))
			env->ray.pos.y -= env->ray.dir.x * env->movespeed;
		}
		if (keycode == A)
		{
			if (check_grid((int)(env->ray.pos.x - env->ray.dir.y
						* env->movespeed), (int)(env->ray.pos.y), env))
			env->ray.pos.x -= env->ray.dir.y * env->movespeed;
			if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
						+ env->ray.dir.x * env->movespeed), env))
			env->ray.pos.y += env->ray.dir.x * env->movespeed;
		}
		if (keycode == W || keycode == UP)
		{
			if (check_grid((int)(env->ray.pos.x + env->ray.dir.x
							* env->movespeed), (int)(env->ray.pos.y), env))
				env->ray.pos.x += env->ray.dir.x * env->movespeed;
			if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
						+ env->ray.dir.y * env->movespeed), env))
				env->ray.pos.y += env->ray.dir.y * env->movespeed;
		}
		if (keycode == S || keycode == DOWN)
		{
			if (check_grid((int)(env->ray.pos.x - env->ray.dir.x
							* env->movespeed), (int)(env->ray.pos.y), env))
				env->ray.pos.x -= env->ray.dir.x * env->movespeed;
			if (check_grid((int)(env->ray.pos.x), (int)(env->ray.pos.y
					- env->ray.dir.y * env->movespeed), env))
				env->ray.pos.y -= env->ray.dir.y * env->movespeed;
		}
		if (keycode == RIGHT)
		{
			env->ray.dir.x = env->ray.dir.x * cos(-env->rotspeed) - env->ray.dir.y * sin(-env->rotspeed);
			env->ray.dir.y = olddir.x * sin(-env->rotspeed) + env->ray.dir.y * cos(-env->rotspeed);
			env->ray.plane.x = env->ray.plane.x * cos(-env->rotspeed) - env->ray.plane.y * sin(-env->rotspeed);
			env->ray.plane.y = oldplane.x * sin(-env->rotspeed) + env->ray.plane.y * cos(- env->rotspeed);
		}
		if (keycode == LEFT)
		{
			env->ray.dir.x = env->ray.dir.x * cos(env->rotspeed)
				- env->ray.dir.y * sin(env->rotspeed);
			env->ray.dir.y = olddir.x * sin(env->rotspeed)
				+ env->ray.dir.y * cos(env->rotspeed);
			env->ray.plane.x = env->ray.plane.x * cos(env->rotspeed)
				- env->ray.plane.y * sin(env->rotspeed);
			env->ray.plane.y = oldplane.x * sin(env->rotspeed)
				+ env->ray.plane.y * cos(env->rotspeed);
		}
		if (env->maze && env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] == 5)
			call_winner(env);
		else
			env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 2;
	}
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of wolf as we know it!", env, 2);
	draw(env);
	return (0);
}
