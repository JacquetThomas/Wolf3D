/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 10:53:01 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/03 14:14:02 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		call_minimap(t_env *env)
{
	t_point	it;
	t_point	map;
	t_point	end;

	it.x = 0;
	end.x = 10;
	map.x = 0;
	while (it.x < env->max_x)
	{
		it.y = 0;
		map.y = 0;
		end.y = 10;
		while (it.y < env->max_y)
		{
			if (env->map[it.y][it.x] == 1)
			{
				square(YELLOW, map.x, map.y, env);
				env->color = BLACK;
				line(map, end, env);
			}
			else if (env->map[it.y][it.x] == 2)
			{
//				printf("it.y : %d // it.x : %d\n", it.y, it.x);
//				printf("cam.y : %d // cam.x : %d\n", env->cam.pos.y, env->cam.pos.x);
				env->color = RED;
				square(RED, map.x, map.y, env);
			}
			map.y += 10;
			end.y += 10;
			it.y++;
		}
		end.x += 10;
		map.x += 10;
		it.x++;
	}
	draw_cmpss(RED, env);
}

void		draw_cmpss(unsigned int color, t_env *env)
{
	t_point	end;
	t_point	rel;

	env->color = color;
	rel.x = (int)env->cam.pos.x * 10 + 5;
	rel.y = (int)env->cam.pos.y * 10 + 5;
	end.x = rel.x + cos(env->cam.angle) * env->cmpss.r;
	end.y = rel.y + sin(env->cam.angle) * env->cmpss.r;
	line(rel, end, env);
}
