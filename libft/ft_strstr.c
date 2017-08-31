/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:19:33 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/08 10:42:11 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	j = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	while (big[j])
	{
		i = 0;
		while (big[j + i] && big[j + i] == little[i])
		{
			i++;
			if (little[i] == '\0')
				return ((char*)&big[j]);
		}
		j++;
	}
	return (NULL);
}
