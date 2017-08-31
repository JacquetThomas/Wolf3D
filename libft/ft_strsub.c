/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:54:51 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:38:07 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (!s)
		return (NULL);
	s1 = (char *)ft_memalloc(len + 1);
	if (s1)
	{
		if (len == 0)
			return (s1);
		s1 = (char *)ft_memcpy((void *)s1, (void *)&s[start], len);
		return (s1);
	}
	return (NULL);
}
