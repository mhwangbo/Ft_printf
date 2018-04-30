#include "includes/ft_printf.h"

int main(void)
{
	ft_printf("unsigned char	a = %hhu	sizeof a = %lu\n", 131, sizeof(131));
	ft_printf("unsigned int	b = %u		sizeof b = %lu\n", 4294967171, sizeof(4294967171));
	ft_printf("unsigned long	c = %lu		sizeof c = %lu\n", 18446744073709551491, sizeof(1844674407370951491));
	ft_printf("unsigned short	d = %hu		sizeof d = %lu\n", 65411, sizeof(65411));
	ft_printf("size_t		e = %zu		sizeof e = %lu\n", 18446744073709551491, sizeof(18446744073709551491));
	return (0);
}

