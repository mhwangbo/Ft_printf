/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 00:09:52 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/09 15:58:47 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_s(long long *n, t_flag flags)
{
	short int	a;
	signed char	b;

	if (flags.length == 2)
	{
		a = (short)*n;
		*n = (long long)a;
	}
	else if (flags.length == 1)
	{
		b = (signed char)*n;
		*n = (long long)b;
	}
}

char	*ft_itoa(long long n, t_flag flags)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	ft_itoa_s(&n, flags);
	len = ft_integerlen(n);
	if (n + 1 == -9223372036854775807)
	{
		str = ft_strdup("-9223372036854775808\0");
		return(str);
	}
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
