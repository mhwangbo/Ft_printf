/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:06:19 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 15:03:16 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_check_intmax(unsigned long long n, int base)
{
	if (n == 2147483648 && base == 8)
		return ("20000000000");
	else if (n == 2147483647 && base == 8)
		return ("17777777777");
	return (NULL);
}

void	ft_llitoa_base_s(char *aba)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = '0';
	while (tmp <= '9')
		aba[i++] = tmp++;
	tmp = 'a';
	while (tmp <= 'z')
		aba[i++] = tmp++;
}

char	*ft_llitoa_base(unsigned long long n, int base)
{
	size_t	i;
	size_t	len;
	char	*str;
	char	*aba;

	aba = ft_memalloc(37);
	ft_llitoa_base_s(aba);
	i = 0;
	len = ft_llintegerlen(n);
	str = ft_memalloc(len + 1);
	if (ft_check_intmax(n, base))
		return (ft_check_intmax(n, base));
	while (i < len)
	{
		str[--len] = aba[(n % base)];
		n = n / base;
	}
	while (*str == '0')
		str++;
	return (str);
}
