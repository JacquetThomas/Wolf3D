/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:59:12 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/12 21:14:15 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		call_raycast(t_env *env)
{
	int		x;

	x = 0;
	while (x < W_WIDTH)
	{
		init_ray(x, &(env)->ray);
		dda(&(env)->ray, env);
		calc_dist(&(env)->ray, env);
		color_wall(env);
		put_line(x, env);
		x++;
	}
}

void		init_ray(int x, t_ray *ray)
{
	ray->camerax = 2 * x / (double)W_WIDTH - 1;
	ray->raypos.x = ray->pos.x;
	ray->raypos.y = ray->pos.y;
	ray->raydir.x = ray->dir.x + ray->plane.x * ray->camerax;
	ray->raydir.y = ray->dir.y + ray->plane.y * ray->camerax;
	ray->map.x = (int)ray->raypos.x;
	ray->map.y = (int)ray->raypos.y;
	ray->deltadist.x = sqrt(1 + (ray->raydir.y * ray->raydir.y)
			/ (ray->raydir.x * ray->raydir.x));
	init_ray2(ray);
}

void		init_ray2(t_ray *ray)
{
	ray->deltadist.y = sqrt(1 + (ray->raydir.x * ray->raydir.x)
			/ (ray->raydir.y * ray->raydir.y));
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->raypos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->raypos.x)
			* ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->raypos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->raypos.y)
			* ray->deltadist.y;
	}
}

void		dda(t_ray *ray, t_env *env)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			env->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			env->side = 1;
		}
		if (env->map[ray->map.x][ray->map.y] == 1)
			hit = 1;
		if (env->map[ray->map.x][ray->map.y] == 5)
			env->exit = 1;
	}
}

void		calc_dist(t_ray *ray, t_env *env)
{
	int	lineheight;

	if (env->side == 0)
		ray->perpwalldist = (ray->map.x - ray->raypos.x
				+ (1 - ray->step.x) / 2) / ray->raydir.x;
	else
		ray->perpwalldist = (ray->map.y - ray->raypos.y
				+ (1 - ray->step.y) / 2) / ray->raydir.y;
	lineheight = (int)(W_HEIGHT / ray->perpwalldist);
	env->wall_h.x = -lineheight / 2 + W_HEIGHT / 2;
	if (env->wall_h.x < 0)
		env->wall_h.x = 0;
	env->wall_h.y = lineheight / 2 + W_HEIGHT / 2;
	if (env->wall_h.y > W_HEIGHT)
		env->wall_h.y = W_HEIGHT - 1;
}
