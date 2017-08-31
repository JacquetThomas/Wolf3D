/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:51:21 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/10 12:18:46 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_white(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t	d;
	size_t	f;
	size_t	i;

	d = 0;
	f = 0;
	if (!s)
		return (NULL);
	while (is_white(s[d]))
		d++;
	i = d;
	while (s[i])
	{
		if (!is_white(s[i]))
		{
			i++;
			f = i;
		}
		else
			i++;
	}
	if (f == 0)
		return (ft_strdup(""));
	return (ft_strsub(s, d, (f - d)));
}
