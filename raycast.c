/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 11:59:12 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/02 17:04:04 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		call_raycast(t_env *env)
{
	int		x;

	x = 0;
	while (x < W_WIDTH)
	{
		init_ray(x, &(env)->cam, env);
		dda(&(env)->ray, env);
		calc_dist(&(env)->ray, env);
		put_line(x, env);
		x++;
	}
}

void		init_ray(int x, t_cam *cam, t_env *env)
{
	cam->realpos.x = 2 * x / (double)W_WIDTH - 1;
	env->ray.pos.x = cam->pos.x;
	env->ray.pos.y = cam->pos.y;
	env->ray.dir.x = cam->dir.x + cam->plane.x * cam->realpos.x;
	env->ray.dir.y = cam->dir.y + cam->plane.y * cam->realpos.x;
	env->ray.map = init_point((int)env->ray.pos.x, (int)env->ray.pos.y);
	env->ray.delta_dist = init_dpoint(sqrt(1 + (env->ray.dir.y * env->ray.dir.y)
				/ (env->ray.dir.x * env->ray.dir.x)),
			sqrt(1 + (env->ray.dir.x * env->ray.dir.x)
				/ (env->ray.dir.y * env->ray.dir.y)));
	init_ray2(&(env)->ray);
}

void		init_ray2(t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (ray->pos.x - ray->map.x) * ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (ray->pos.y - ray->map.y) * ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->delta_dist.y;
	}
}

void		dda(t_ray *ray, t_env *env)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		/* jump to next ray->map. square, OR in x-direction, OR in y-direction*/
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			env->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			env->side = 1;
		}
		/*Check if ray has hit a wall*/
		if (env->map[ray->map.x][ray->map.y] > 0)
			hit = 1;
	}
}

void		calc_dist(t_ray *ray, t_env *env)
{
	int	lineHeight;

	if (env->side == 0)
		ray->wall_dist = (ray->map.x - ray->pos.x +
				(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->wall_dist = (ray->map.y - ray->pos.y +
				(1 - ray->step.y) / 2) / ray->dir.y;
	lineHeight = (int)(W_HEIGHT / ray->wall_dist);
	env->wall_h.x = -lineHeight / 2 + (double)W_HEIGHT / 2;
	if(env->wall_h.x < 0)
		env->wall_h.x = 0;
	env->wall_h.y = lineHeight / 2 + (double)W_HEIGHT / 2;
	if(env->wall_h.y >= W_HEIGHT)
		env->wall_h.y = W_HEIGHT - 1;
}
