/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:52:37 by cjacquet          #+#    #+#             */
/*   Updated: 2017/08/31 13:39:58 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

unsigned int	b_or_w(t_env *env)
{
	int		toto;

	toto = env->fract_name;
	if (toto == 2 || toto == 3 || toto == 5)
		return (0);
	if (env->color_picker)
		return (254);
	return (0);
}

unsigned int	get_color(float h, float s, float l, t_env *env)
{
	int			uni;
	t_hsl		calc;
	t_color		color;

	if (h == 360)
	{
		uni = b_or_w(env);
		return (((uni << 16) + (uni << 8) + uni));
	}
	h = fmod((h + env->color_m), 360.0);
	init_hsl(&calc, h, s, l);
	if (calc.t < 1)
		choose_rgb(calc.c, calc.x, 0, &color);
	else if (calc.t < 2)
		choose_rgb(calc.x, calc.c, 0, &color);
	else if (calc.t < 3)
		choose_rgb(0, calc.c, calc.x, &color);
	else if (calc.t < 4)
		choose_rgb(0, calc.x, calc.c, &color);
	else if (calc.t < 5)
		choose_rgb(calc.x, 0, calc.c, &color);
	else
		choose_rgb(calc.c, 0, calc.x, &color);
	calc_rgb(l, &calc, &color);
	return (((color.rr << 16) + (color.gg << 8) + color.bb));
}

void			init_hsl(t_hsl *calc, float h, float s, float l)
{
	calc->c = l * s;
	calc->t = h / 60;
	calc->x = calc->c * (1.0 - fabs(fmod(calc->t, 2) - 1.0));
}

void			calc_rgb(float l, t_hsl *calc, t_color *color)
{
	calc->m = l - calc->c;
	color->rr = (int)((color->r + calc->m) * 255);
	color->gg = (int)((color->g + calc->m) * 255);
	color->bb = (int)((color->b + calc->m) * 255);
}

float			choose_rgb(float r, float g, float b, t_color *c)
{
	c->r = r;
	c->g = g;
	c->b = b;
	return (42.0);
}
