/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/09 15:30:25 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		color_wall(t_env *env)
{
	if (env->side == 0)
		env->color = (env->ray.step.x == -1) ? GREEN : BLUE;
	else
		env->color = (env->ray.step.y == -1) ? ORANGE : RED;
}
