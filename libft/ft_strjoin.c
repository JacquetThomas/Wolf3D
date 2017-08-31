/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:54:51 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/09 14:43:06 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1)
		return (NULL);
	s = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s)
	{
		s = ft_strcpy(s, s1);
		s = ft_strcat(s, s2);
		return (s);
	}
	return (NULL);
}
