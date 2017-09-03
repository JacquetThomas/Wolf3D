/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 14:55:33 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/03 14:15:58 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move_player(int nb, t_env *env)
{
	double	tmpx;
	double	tmpy;

	tmpx = env->cam.pos.x + (env->cam.speed * cos(env->cam.angle)) * nb;
	tmpy = env->cam.pos.y + (env->cam.speed * sin(env->cam.angle)) * nb;
	printf("tmpx : %f // tmpy : %f\n", tmpx, tmpy);
	printf("cam.x : %f // cam.y : %f\n", env->cam.pos.x, env->cam.pos.y);
	square(BLACK, (int)env->cam.pos.x * 10, (int)env->cam.pos.y * 10, env);
	env->map[(int)env->cam.pos.y][(int)env->cam.pos.x] = 0;
	if (env->map[(int)env->cam.pos.y][(int)tmpx] == 0)
		env->cam.pos.x = tmpx;
	if (env->map[(int)tmpy][(int)env->cam.pos.x] == 0)
		env->cam.pos.y = tmpy;
	env->map[(int)env->cam.pos.y][(int)env->cam.pos.x] = 2;
}

double		deg2rad(double angle)
{
	return (M_PI * (angle) / 180 );
}

double		rad2deg(double angle)
{
	return (180 * (angle) / M_PI);
}

t_point		init_point(int x, int y)
{
	t_point	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_dpoint	init_dpoint(double x, double y)
{
	t_dpoint	new;

	new.x = x;
	new.y = y;
	return (new);
}

int			test_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!is_white(str[i]) && str[i] != '-' && !is_num(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int			is_num(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == '4');
}
