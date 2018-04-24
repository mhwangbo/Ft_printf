/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:16:04 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/24 16:27:34 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_whtspace(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int			ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		r;

	i = 0;
	sign = 1;
	r = 0;
	i = ft_whtspace(s, i);
	if (s[i] == '-')
	{
		if (s[i + 1] == '-' || s[i + 1] == '+')
			return (0);
		i++;
		sign = -1;
	}
	if (s[i] == '+')
		i++;
	while ((s[i] != '\0') && (s[i] >= '0') && (s[i] <= '9'))
	{
		r = (r * 10) + (s[i] - '0');
		i++;
	}
	return (sign * r);
}
