/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:19:33 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:40:23 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (big[j])
	{
		i = 0;
		while (i + j < len && little[i] && big[j + i] == little[i])
			i++;
		if (little[i] == 0)
			return ((char *)&big[j]);
		j++;
	}
	if (i >= len)
		return (NULL);
	if (big[j] == little[i])
		return ((char *)&big[j]);
	return (NULL);
}
