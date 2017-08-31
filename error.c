/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:58:16 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:40:24 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	error_init(t_env *env, int mode)
{
	error_str("Error at initialization\n", env, mode);
}

void	error_str(char *str, t_env *env, int mode)
{
	ft_putendl(str);
	if (mode == 1)
		free_all(env);
	if (env->music == 1)
		system("killall afplay");
	exit(0);
}

void	free_all(t_env *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
}
