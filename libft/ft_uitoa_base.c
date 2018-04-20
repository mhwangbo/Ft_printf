/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:06:19 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/18 20:08:01 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_uitoa_base(unsigned int n, int base)
{
	size_t	i;
	size_t	len;
	char	*str;
	char	*aba;

	aba = ft_memalloc(37);
	aba = "0123456789abcdefghijklmnopqrstuvwxyz\0";
	i = 0;
	len = ft_integerlen((int)n);
	str = ft_memalloc(len + 1);
	while (i < len)
	{
		str[--len] = aba[(n % base)];
		n = n / base;
	}
	while (*str == '0')
		str++;
	return (str);
}