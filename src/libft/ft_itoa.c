/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 00:09:52 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 16:45:49 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_integerlen(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = 0;
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
	}
	while (i < len)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
