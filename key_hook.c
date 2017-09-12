/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:46:41 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 20:07:28 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_env *env)
{
	if (env->maze)
		checking_time(env);
	if (keycode == 4)
	{
		if (env->help)
			destroy_help(env);
		else
			create_help(env);
	}
	if (keycode == 18)
	{
		if (!env->maze)
		{
			env->start = time(NULL);
			if (env->music)
				system("killall afplay");
			system("afplay Ressources/stress.mp3 &");
			env->music = 1;
			env->maze = 1;
			call_minimap(env);
		}
	}
	key_hook2(keycode, env);
	return (1);
}

int		key_hook2(int keycode, t_env *env)
{
	if (keycode == 257)
	{
		if (env->run == 2)
			env->run = 1;
		else
			env->run = 2;
	}
	if (keycode == 19)
	{
		if (env->maze)
		{
			if (env->music)
			{
				system("killall afplay");
				system("afplay Ressources/wait.mp3 &");
			}
			env->maze = 0;
		}
	}
	key_hook3(keycode, env);
	return (1);
}

int		key_hook3(int keycode, t_env *env)
{
	if (moving_key(keycode))
	{
		print_player(BLACK, env);
		env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 0;
		if (keycode == D)
			move_right(env);
		if (keycode == A)
			move_left(env);
		if (keycode == W || keycode == UP)
			move_up(env);
		if (keycode == S || keycode == DOWN)
			move_down(env);
		if (keycode == RIGHT || keycode == LEFT)
			rotate(keycode, env);
		if (env->maze
				&& env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] == 5)
			call_winner(env);
		else
			env->map[(int)env->ray.pos.x][(int)env->ray.pos.y] = 2;
	}
	key_hook4(keycode, env);
	return (1);
}

int		key_hook4(int keycode, t_env *env)
{
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
			if (env->maze == 1)
				system("afplay Ressources/stress.mp3 &");
			else
				system("afplay Ressources/wait.mp3 &");
		}
	}
	if (keycode == 53 || keycode == 12)
		error_str("It's the end of wolf as we know it!", env, 2);
	draw(env);
	return (0);
}

int		exit_cross(t_env *env)
{
	if (env->music)
		system("killall afplay");
	if (env->maze)
		error_str("Give up is for the loser!", env, 2);
	else
		error_str("It's the end of wolf as we know it!", env, 2);
	return (0);
}
