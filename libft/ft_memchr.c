/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:16:23 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:39:10 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*s1;

	i = 0;
	ch = (unsigned char)c;
	s1 = (unsigned char*)s;
	while (i < n - 1 && s1[i] != ch)
		i++;
	if (s1[i] == ch)
		return (&((void*)s)[i]);
	return (NULL);
}
