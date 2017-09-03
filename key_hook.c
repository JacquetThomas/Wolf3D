/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/03 12:55:09 by cjacquet         ###   ########.fr       */
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
	if (keycode == UP || keycode == DOWN ||keycode == RIGHT || keycode == LEFT)
	{
		printf("cam.angle : %f\n", env->cam.angle);
		draw_cmpss(BLACK, env);
		if (keycode == RIGHT)
			env->cam.angle += env->cam.rotspeed;
		if (keycode == LEFT)
			env->cam.angle -= env->cam.rotspeed;
		if (keycode == DOWN)
			move_player(-1, env);
		if (keycode == UP)
			move_player(1, env);
		draw_cmpss(RED, env);
	}
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of wolf as we know it!", env, 2);
	draw(env);
	return (0);
}
