/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:58:45 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:44:50 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	l = ft_strlen(s1);
	s2 = (char*)malloc(l + 1);
	if (s2)
	{
		ft_strcpy(s2, s1);
		return (s2);
	}
	else
		return (NULL);
}
