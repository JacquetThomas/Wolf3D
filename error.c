/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:58:16 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 21:57:29 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	error_init(t_env *env, int mode)
{
	error_str("Error at initialization\n", env, mode);
}

void	error_str(char *str, t_env *env, int mode)
{
	char	*ito;

	ft_putendl(str);
	if (env->music == 1)
		system("killall afplay");
	if (mode >= 2)
		free_all(env);
	else if (mode == 1)
		free_no_win(env);
	if (mode == 5)
	{
		ito = ft_itoa(env->now - env->start);
		ft_putstr("You win in ");
		ft_putstr(ito);
		ft_putendl(" sec!");
		free(ito);
	}
	exit(0);
}
