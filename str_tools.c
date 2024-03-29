/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:56:05 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/28 15:50:01 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_dpoint		search_player(char *map, t_env *env)
{
	t_dpoint	iter;

	iter.y = 0;
	get_map(map, env);
	while (iter.y < env->max_y)
	{
		iter.x = 0;
		while (iter.x < env->max_x)
		{
			if (env->map[(int)iter.x][(int)iter.y] == 2)
			{
				iter.x += 0.02;
				iter.y += 0.02;
				return (iter);
			}
			iter.x++;
		}
		iter.y++;
	}
	return (iter);
}

int				tab_len(char **tab)
{
	int			i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int				is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*readfile(int fd)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int		ret;
	int		flag;

	flag = 0;
	if (!(buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		exit(0);
	line = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && flag == 0)
	{
		buff[ret] = '\0';
		tmp = line;
		flag = test_line(buff);
		line = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (line);
}

int				is_wolfmap(char *str)
{
	int		len;

	len = ft_strlen(str);
	return (str[len - 1] == 'f' && str[len - 2] == 'l' && str[len - 3] == 'o'
			&& str[len - 4] == 'w' && str[len - 5] == '.');
}
