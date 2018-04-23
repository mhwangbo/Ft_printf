/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:42:51 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/03/10 15:18:19 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordlen(char const *str, char c)
{
	int i;

	if (!str || !c)
		return (0);
	i = 0;
	while (c == str[i] && str[i] != '\0')
		str++;
	while (c != str[i] && str[i] != '\0')
		i++;
	return (i);
}
