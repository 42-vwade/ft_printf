#include "libft/libft.h"
#include <stdio.h>

int
	main(void)
{
	int	base = 10;
	int	a = 16;

	ft_putendl(ft_itoa_base(a, base--));
	ft_putendl(ft_itoa_base(a, base--));
	ft_putendl(ft_itoa_base(a, base--));
	ft_putendl(ft_itoa_base(a, base--));
	ft_putendl(ft_itoa_base(a, base--));
	ft_putendl(ft_itoa_base(a, base));
}
