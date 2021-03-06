/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:22:23 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/26 19:31:27 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhite(const char s)
{
	if ((s == ' ') || (s == '\v') || (s == '\t') || (s == '\f') ||
			(s == '\r') || (s == '\n'))
		return (1);
	else
		return (0);
}
