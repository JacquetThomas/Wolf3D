/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/10 17:06:01 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *env)
{
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
	if (keycode == UP)
	{
		printf("env->view = %d // W_HEIGHT / 2 : %d\n", env->view, W_HEIGHT / 2);
		env->view = (env->view < W_HEIGHT / 2 - 4) ? env->view + 3 : env->view;
	}
	if (keycode == DOWN)
	{
		printf("-env->view = %d // W_HEIGHT / 2 : %d\n", env->view, W_HEIGHT / 2);
		env->view = (env->view > -(W_HEIGHT / 2) - 4) ? env->view - 3 : env->view;
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
//		printf("pos.x : %f // pos.y : %f\n", env->ray.pos.x, env->ray.pos.y);
		printf("dir.x : %f // dir.y : %f\n", env->ray.dir.x, env->ray.dir.y);
		print_player(BLACK, env);
		env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 0;
		if (keycode == D)
		{
			env->ray.pos.x += (env->ray.dir.x - 0.5) * env->movespeed;
			env->ray.pos.y += (env->ray.dir.y - 1) * env->movespeed;
		}
		if (keycode == A)
		{
			env->ray.pos.x -= (env->ray.dir.x + 1) * env->movespeed;
			env->ray.pos.y -= (env->ray.dir.y + 0.5) * env->movespeed;
		}
		if (keycode == W)
		{
			if(env->map[(int)(env->ray.pos.x + env->ray.dir.x * env->movespeed)][(int)(env->ray.pos.y)] == 0)
				env->ray.pos.x += env->ray.dir.x * env->movespeed;
			if(env->map[(int)(env->ray.pos.x)][(int)(env->ray.pos.y
						+ env->ray.dir.y * env->movespeed)] == 0)
				env->ray.pos.y += env->ray.dir.y * env->movespeed;
		}
		if (keycode == S)
		{
			if(env->map[(int)(env->ray.pos.x - env->ray.dir.x * env->movespeed)][(int)(env->ray.pos.y)] == 0)
				env->ray.pos.x -= env->ray.dir.x * env->movespeed;
			if(env->map[(int)(env->ray.pos.x)][(int)(env->ray.pos.y - env->ray.dir.y * env->movespeed)] == 0)
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
		env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 2;
//		print_player(RED, env);
//		printf("--dir.x : %f // dir.y : %f\n", env->ray.dir.x, env->ray.dir.y);
	}
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of wolf as we know it!", env, 2);
	draw(env);
	return (0);
}
