/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integerlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:31:27 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/23 15:44:48 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_llintegerlen(unsigned long long n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		n = n / 10;
		l++;
	}
	return (l);
}
