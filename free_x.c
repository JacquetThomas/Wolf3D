/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 15:26:20 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/02 14:09:34 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_no_win(t_env *env)
{
	if (env->tab_file)
		free_tab(env->tab_file);
}

void	free_all(t_env *env)
{
	free_no_win(env);
	if (env->line)
		free(env->line);
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->map)
		free_map(env);
}

void	free_map(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->max_y)
	{
		free(env->map[i]);
		i++;
	}
	free(env->map);
}
