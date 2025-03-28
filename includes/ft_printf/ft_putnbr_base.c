
#include "ft_printf.h"

long	ft_putnbr_base(long n, int baseSize, char *baseChars)
{
	int		count;

	count = 0;
	if (n < 0 && baseSize == 10)
	{
		write(1, "-", 1);
		return (ft_putnbr_base(-n, baseSize, baseChars) + 1);
	}
	else if (n < 0 && baseSize == 16)
		return (ft_putnbr_base(-n, baseSize, baseChars) + 1);
	else if (n < baseSize)
		return (ft_putchar(baseChars[n]));
	else
	{
		count = ft_putnbr_base(n / baseSize, baseSize, baseChars);
		return (count + ft_putnbr_base(n % baseSize, baseSize, baseChars));
	}
}
