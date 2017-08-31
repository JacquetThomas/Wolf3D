/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:56:05 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:42:04 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		is_fract_name(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot"))
		return (0);
	if (!ft_strcmp(str, "Julia"))
		return (1);
	if (!ft_strcmp(str, "Newton"))
		return (2);
	else
		return (42);
}

int		is_alnum_comma(char c)
{
	return (ft_isalnum(c) || c == ',');
}

int		is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
