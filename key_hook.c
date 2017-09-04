/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/04 16:31:34 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *env)
{
/*	if (keycode == 35)
	{
		env->color_picker = (env->color_picker) ? 0 : 1;
		if (env->color_picker)
		{
			if (env->music)
			{
				system("killall afplay");
				system("afplay psych.mp3 &");
			}
		}
		else
		{
			if (env->music)
			{
				system("killall afplay");
				system("afplay wait.mp3 &");
			}
		}
	}
*/	key_hook2(keycode, env);
	return (1);
}

int		key_hook2(int keycode, t_env *env)
{
/*	if ((keycode >= 18 && keycode <= 23) || keycode == 26 || keycode == 28)
	{
		if (keycode == 18)
			env->fract_name = 0;
		if (keycode == 19)
			env->fract_name = 1;
		if (keycode == 20)
			env->fract_name = 2;
		if (keycode == 21)
			env->fract_name = 3;
		if (keycode == 23)
			env->fract_name = 4;
		if (keycode == 22)
			env->fract_name = 5;
		if (keycode == 26)
			env->fract_name = 6;
		if (keycode == 28)
			env->fract_name = 7;
		maj_var(env);
	}
*/	key_hook3(keycode, env);
	return (1);
}

int		key_hook3(int keycode, t_env *env)
{
/*	if (keycode == 4)
	{
		if (env->help)
			destroy_help(env);
		else
			create_help(env);
	}
	if (keycode == 46)
	{
		if (env->music)
		{
			env->music = 0;
			system("killall afplay");
		}
		else
		{
			env->music = 1;
			if (env->color_picker == 0)
				system("afplay wait.mp3 &");
			else
				system("afplay psych.mp3 &");
		}
	}
*/	key_hook4(keycode, env);
	return (1);
}

int		key_hook4(int keycode, t_env *env)
{
/*	if (keycode == 27 || keycode == 24)
		zoom(keycode, env);
	if (keycode == 37)
		env->c_lock = (env->c_lock) ? 0 : 1;
	if (keycode == 38)
		env->move_r = (env->move_r) ? 0 : 1;
	if (keycode == 40)
		env->move_i = (env->move_i) ? 0 : 1;
	env->max_i += (keycode == 69) ? 1 : 0;
	env->max_i -= (keycode == 78 && env->max_i > 1) ? 1 : 0;
	if (keycode == 34)
		env->auto_i = (env->auto_i) ? 0 : 1;
	if (keycode == 5)
		env->grey = (env->grey) ? 0 : 1;
	if (keycode == 6)
		maj_var(env);
*/	key_hook5(keycode, env);
	return (1);
}

int		key_hook5(int keycode, t_env *env)
{
	t_dpoint		olddir;
	t_dpoint		oldplane;

	oldplane = env->ray.plane;
	olddir = env->ray.dir;
	if (keycode == UP || keycode == DOWN ||keycode == RIGHT || keycode == LEFT)
	{
		printf("dir.x : %f // dir.y : %f\n", env->ray.dir.x, env->ray.dir.y);
		draw_cmpss(BLACK, env);
		square(BLACK, env->ray.pos.x * 10, env->ray.pos.y * 10, env);
		env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 0;
		if (keycode == UP)
		{
			if(env->map[(int)(env->ray.pos.x + env->ray.dir.x * env->movespeed)][(int)(env->ray.pos.y)] == 0)
				env->ray.pos.x += env->ray.dir.x * env->movespeed;
			if(env->map[(int)(env->ray.pos.x)][(int)(env->ray.pos.y
						+ env->ray.dir.y * env->movespeed)] == 0)
				env->ray.pos.y += env->ray.dir.y * env->movespeed;
		}
		//move backwards if no wall behind you
		if (keycode == DOWN)
		{
			if(env->map[(int)(env->ray.pos.x - env->ray.dir.x * env->movespeed)][(int)(env->ray.pos.y)] == 0)
				env->ray.pos.x -= env->ray.dir.x * env->movespeed;
			if(env->map[(int)(env->ray.pos.x)][(int)(env->ray.pos.y - env->ray.dir.y * env->movespeed)] == 0)
				env->ray.pos.y -= env->ray.dir.y * env->movespeed;
		}
		//rotate to the right
		if (keycode == RIGHT)
		{
			//both camera direction and camera plane must be rotated
			env->ray.dir.x = env->ray.dir.x * cos(-env->rotspeed) - env->ray.dir.y * sin(-env->rotspeed);
			env->ray.dir.y = olddir.x * sin(-env->rotspeed) + env->ray.dir.y * cos(-env->rotspeed);
			env->ray.plane.x = env->ray.plane.x * cos(-env->rotspeed) - env->ray.plane.y * sin(-env->rotspeed);
			env->ray.plane.y = oldplane.x * sin(-env->rotspeed) + env->ray.plane.y * cos(- env->rotspeed);
		}
		//rotate to the left
		if (keycode == LEFT)
		{
			//both camera direction and camera plane must be rotated
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
		draw_cmpss(RED, env);
		square(RED, env->ray.pos.x * 10, env->ray.pos.y * 10, env);
		printf("--dir.x : %f // dir.y : %f\n", env->ray.dir.x, env->ray.dir.y);
	}
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of wolf as we know it!", env, 2);
	draw(env);
	return (0);
}
