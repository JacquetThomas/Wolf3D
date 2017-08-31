/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:33:38 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:39:29 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	void	*s1;

	i = 0;
	s1 = (void*)malloc(len);
	if (s1)
	{
		while (i < len)
		{
			((char*)s1)[i] = ((char*)src)[i];
			i++;
		}
		i = 0;
		while (i < len)
		{
			((char*)dst)[i] = ((char*)s1)[i];
			i++;
		}
		free(s1);
	}
	return (dst);
}
