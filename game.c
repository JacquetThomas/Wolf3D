/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:48:07 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/11 19:15:44 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	checking_time(t_env *env)
{
	env->now = time(NULL);

	if (env->now - env->start > 180)
		call_loser(env);
}

void	call_winner(t_env *env)
{
	error_str("Well done!", env, 5);
}

void	call_loser(t_env *env)
{
	error_str("You're too slow, try again!", env, 4);
}

int		check_grid(int x, int y, t_env *env)
{
	return (env->map[x][y] == 0 || env->map[x][y] == 5);
}
