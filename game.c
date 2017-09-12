/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 18:48:07 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 17:07:18 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	checking_time(t_env *env)
{
	env->now = time(NULL);
	if (env->now - env->start > M_TIME)
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

void	countdown(void)
{
	int	i;

	i = 10;
	while (i > 0)
	{
		ft_putnbr(i);
		ft_putendl("..");
		sleep(1);
		i--;
	}
}

int		check_grid(int x, int y, t_env *env)
{
	return (env->map[x][y] == 0 || env->map[x][y] == 5);
}
