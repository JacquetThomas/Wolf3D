/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:42:31 by cjacquet          #+#    #+#             */
/*   Updated: 2017/03/09 17:30:28 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUFF_SIZE 100
# define MAX_INT 2147483647
# define MAX_FD 2560

typedef struct	s_stock
{
	char	*tab[MAX_FD + 1];
	char	*buff;
	char	*tmp;
	int		read_b;
}				t_stock;

int				get_next_line(const int fd, char **line);

#endif
