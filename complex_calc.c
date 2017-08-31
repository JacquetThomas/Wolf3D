/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 11:39:26 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:40:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_plex	c_mul(t_plex un, t_plex deux)
{
	t_plex	new;

	new.r = un.r * deux.r - un.i * deux.i;
	new.i = un.r * deux.i + un.i * deux.r;
	return (new);
}

t_plex	c_add(t_plex un, t_plex deux)
{
	t_plex	new;

	new.r = un.r + deux.r;
	new.i = un.i + deux.i;
	return (new);
}

t_plex	c_sous(t_plex un, t_plex deux)
{
	t_plex	new;

	new.r = un.r - deux.r;
	new.i = un.i - deux.i;
	return (new);
}

t_plex	c_div(t_plex un, t_plex deux)
{
	t_plex	new;
	t_plex	conj;
	t_plex	tmp;

	conj.r = deux.r;
	conj.i = -deux.i;
	tmp = c_mul(un, conj);
	new.r = tmp.r / ((deux.r * deux.r) + (deux.i * deux.i));
	new.i = tmp.i / ((deux.r * deux.r) + (deux.i * deux.i));
	return (new);
}

t_plex	map(int x, int y, t_env *env, int pxy)
{
	t_plex	new;

	if (pxy != 2)
	{
		new.r = ((float)x / W_WIDTH) * (env->max_x - env->min_x) + env->min_x;
		new.i = ((float)y / W_HEIGHT) * (env->max_y - env->min_y) + env->min_y;
		if (pxy == 1)
		{
			new.r += env->px;
			new.i += env->py;
		}
	}
	if (pxy == 2)
	{
		new.r = ((float)x / W_WIDTH) * (1 - (-1)) + (-1);
		new.i = ((float)y / W_HEIGHT) * (1 - (-1)) + (-1);
	}
	return (new);
}
