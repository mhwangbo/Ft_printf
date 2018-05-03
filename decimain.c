/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 21:40:49 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/02 23:57:18 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	ft_printf("f: [%f]\n", 10.111111);
	printf("f: [%f]\n", 10.111111);
	ft_printf(" f: [% f]\n", 1314.9);
	printf(" f: [% f]\n", 1314.9);
	ft_printf(".2f: [%.2f]\n", 319.1314);
	printf(".2f: [%.2f]\n", 319.1314);
	ft_printf("+f: [%+f]\n", (double)124);
	printf("+f: [%+f]\n", (double)124);
	ft_printf("f: [%f]\n", (double)0);
	printf("f: [%f]\n", (double)0);
	ft_printf("10f: [%10f]\n", 123.132);
	printf("10f: [%10f]\n", 123.132);
	ft_printf("-10.2f: [%-10.2f]\n", 123.132);
	printf("-10.2f: [%-10.2f]\n", 123.132);
	return (0);
}

