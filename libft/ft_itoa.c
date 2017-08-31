/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:30:13 by cjacquet          #+#    #+#             */
/*   Updated: 2016/11/14 12:43:18 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nb_len(long long int n)
{
	int len;

	len = 2;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char				*str;
	long long int		nb;
	int					len;

	nb = n;
	len = ft_nb_len(nb);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	if (n < 0)
		nb = nb * -1;
	len = len - 2;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		len--;
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
