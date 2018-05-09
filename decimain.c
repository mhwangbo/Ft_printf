/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:19:09 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/05/08 16:31:33 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	ft_printf("%a", (double)-42);
	ft_printf("Kashim a %a histoire a raconter", (double)-1001);
	ft_printf("Il fait au moins %a ", (double)-4294959296);
	ft_printf("%a", (double)0);
	ft_printf("%a", (double)0);
	ft_printf("%a", (double)-2147483647);
	ft_printf("%a", (double)2147483648);
	ft_printf("%%a 0000042 == |%a|", (double)-0000042);
	ft_printf("%%a == |%a|", (double)-42.42);
	ft_printf("%%a Lydie == |%a|\n", (double)-503);
	int	i;
	ft_printf("LALALALALAL\n%n", &i);
	ft_printf("%d\n", i);
	ft_printf("Kashim a %d histoires à raconter\n%n", 1001, &i);
	ft_printf("%d\n", i);
	ft_printf("%d%n", 9, &i);
	ft_printf("%d\n", i);
	ft_printf("\n");
	printf("pr %%g == |%g|\n", 100000000000.123123);
	printf("%g\n", 110417492834.12420421098);
	printf("%e\n", 110417492834.12420421098);
	printf("pr: %g\n", 1.1242421098);
	ft_printf("ft: %g\n", 1.1242421098);
	printf("pr: %g\n", 1.4211293);
	ft_printf("ft: %g\n", 1.4211293);
	printf("%f\n", 1.4211293);
	ft_printf("ft %%g == |%e|\n", 100000000000.123123);
	printf("pr: %e\n", -8000.0);
	ft_printf("ft: %e\n", -8000.0);
	return (0);
}
