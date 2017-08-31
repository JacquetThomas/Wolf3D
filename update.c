/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:22:58 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:41:55 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		maj_julia(t_env *env)
{
	static int	flag = 0;
	static int	flag2 = 0;
	double		toto;

	toto = 1 * (env->move / 10);
	if (env->c_lock && env->move_r)
	{
		env->julia.r = (flag == 0) ? env->julia.r + toto : env->julia.r - toto;
		if (env->julia.r > 1)
			flag = 1;
		else if (env->julia.r < -1)
			flag = 0;
	}
	if (env->c_lock && env->move_i)
	{
		env->julia.i = (flag2 == 0) ? env->julia.i + toto : env->julia.i - toto;
		if (env->julia.i > 1)
			flag2 = 1;
		else if (env->julia.i < -1)
			flag2 = 0;
	}
}

void		maj_var(t_env *env)
{
	env->px = 0;
	env->py = 0;
	env->move = 0.1;
	env->move_r = 0;
	env->move_i = 0;
	env->max_x = 2.0;
	env->max_y = 2.0;
	env->min_x = -2.0;
	env->min_y = -2.0;
	env->color_m = 5;
	env->grey = 0;
	env->nvar = (env->fract_name == 3) ? 1 : 0;
	env->max_i = maj_iter(env->fract_name);
	env->auto_i = 0;
}

int			maj_iter(int fract)
{
	if (fract == 5)
		return (35);
	else if (fract == 2)
		return (10);
	else if (fract == 3)
		return (25);
	else
		return (72);
}

void		zoom(int keycode, t_env *env)
{
	if (keycode == 27)
		mouse_hook(2, 300, 400, env);
	else
		mouse_hook(1, 300, 400, env);
}
