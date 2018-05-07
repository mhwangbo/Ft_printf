/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:19:09 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/06 21:56:03 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	int c;
	printf("GEEKS FOR %s HELlO HELLØ %d%n\n", "HELLO WORLD", 1235146, &c);
	printf("%d\n", c);
	int d;
	ft_printf("GEEKS FOR %s HELlO HELLØ %d %n\n", "HELLO WORLD", 1235146, &d);
	printf("%d\n", c);
	ft_printf("\n");
	ft_printf("%a\n", 10.1010);
	ft_printf("\n");
	ft_printf("%A\n", 5165846513213551315351314654.32103);
	ft_printf("\n");
	return (0);
}
