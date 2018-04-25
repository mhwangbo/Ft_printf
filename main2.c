/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhwangbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 23:37:08 by mhwangbo          #+#    #+#             */
/*   Updated: 2018/04/25 14:18:44 by mhwangbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	int		r1=0, r2=0;

	ft_printf("TEST_c::::\n");
	r1 = ft_printf("%c", '*');
	r2 = printf("%c", '*');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
//	r1 = ft_printf("Kashim a %c histoires à raconter", '�');
//	r2 = printf("Kashim a %c histoires à raconter", '�');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
//	r1 = ft_printf("Il fait au moins %c\n", '�');
//	r2 = printf("Il fait au moins %c\n", '�');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", '\n');
	r2 = printf("%c", '\n');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", '\n');
	r2 = printf("%c", '\n');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
//	r1 = ft_printf("%c\n", '�');
//	r2 = printf("%c\n", '�');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c\n", 'c');
	r2 = printf("%c\n", 'c');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c\n", '\n');
	r2 = printf("%c\n", '\n');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", 'l');
	r2 = printf("%c", 'l');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", 'y');
	r2 = printf("%c", 'y');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", ' ');
	r2 = printf("%c", ' ');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", 'e');
	r2 = printf("%c", 'e');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c", 's');
	r2 = printf("%c", 's');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);
	r1 = ft_printf("%c\n", '!');
	r2 = printf("%c\n", '!');
	ft_printf("r1 [%d] r2[%d]\n", r1, r2);

	return (0);
}
