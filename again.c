/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   again.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:31:30 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:39:41 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	again(t_env *env)
{
	set_var(env);
	free_all(env);
	if (!(env->win = mlx_new_window(env->mlx, W_WIDTH, W_HEIGHT + 100,
					fract_name(env))))
		error_init(env, 2);
	if (env->music)
		system("afplay wait.mp3 &");
}
