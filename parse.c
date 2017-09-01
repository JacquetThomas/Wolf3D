/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 13:32:31 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/01 16:44:27 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			get_map(char *file, t_env *env)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) > 0)
		env->line = read_file(fd);
	else
		error_str("Map doesn't exist dude.", env, 0);
	env->tab_file = ft_strsplit(env->line, '\n');
	env->max_y = tab_len(env->tab_file);
	if (env->max_y > 2 && (env->max_x = check_nb(env->tab_file)) > 2)
		set_map(env, env->tab_file);
	else
		error_str("Wrong map_file", env, 1);
}

void			set_map(t_env *env, char **tab_file)
{
	int		i;

	i = 0;
	if (!(env->map = (int **)malloc(sizeof(int*) * env->max_y)))
		error_str("Error at initialisation, sorry.", env, 1);
	while (i < env->max_y)
	{
		env->map[i] = dup_nb(env, tab_file[i]);
		i++;
	}
}

int				*dup_nb(t_env *env, char *line)
{
	int		*nbr;
	int		i;
	int		cpt;

	if (!line)
		return (NULL);
	if (!(nbr = (int *)malloc(sizeof(int) * env->max_x)))
		return (NULL);
	i = 0;
	cpt = 0;
	while (line[i])
	{
		while (line[i] && is_white(line[i]))
			i++;
		if (cpt < env->max_x)
		{
			nbr[cpt++] = ft_atoi(&line[i]);
			while (line[i] && is_num(line[i]))
				i++;
		}
	}
	return (nbr);
}

int				check_nb(char **s)
{
	int		j;
	int		base;
	int		tmp;

	j = 0;
	base = 0;
	while (s[j])
	{
		printf("s[%d] = %s\n", j, s[j]);
		tmp = count_nb(s[j]);
		if (j == 0)
			base = tmp;
		else
		{
			if (base != tmp)
				return (-1);
		}
		j++;
	}
	return (base);
}

int				count_nb(char *s)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (!is_white(s[i]) && !is_num(s[i]))
			return (-1);
		while (s[i] && is_white(s[i]))
			i++;
		if (s[i] && !is_white(s[i]) && is_num(s[i]))
		{
			cpt++;
			while (s[i] && is_num(s[i]))
				i++;
		}
		else
			i++;
	}
	return (cpt);
}
