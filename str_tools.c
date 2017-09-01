/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:56:05 by cjacquet          #+#    #+#             */
/*   Updated: 2017/09/01 14:41:33 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_point		search_player(char *map, t_env *env)
{
	t_point	iter;

	iter.y = 0;
	get_map(map, env);
	while (iter.y < env->max_y)
	{
		iter.x = 0;
		while (iter.x < env->max_x)
		{
//			printf("content[%d][%d] = %d\n", iter.y, iter.x,
//					env->map[iter.y][iter.x]);
			if (env->map[iter.y][iter.x] == 2)
				return (iter);
			iter.x++;
		}
		iter.y++;
	}
	return (iter);
}

int			tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int			is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*read_file(int fd)
{
	char	*buff;
	char	*line;
	char	*tmp;
	int		ret;

	buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	line = ft_strnew(1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = line;
		line = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (line);
}

int			is_wolfmap(char *str)
{
	int		len;

	len = ft_strlen(str);
	return (str[len - 1] == 'f' && str[len - 2] == 'l' && str[len - 3] == 'o'
			&& str[len - 4] == 'w' && str[len - 5] == '.');
}
